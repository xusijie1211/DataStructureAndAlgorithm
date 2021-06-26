#!/bin/bash
#

. $(find . -name "BUILD_PKG.sh" -print)

# building process num, for make processes.
BUILD_PROCESSES=8

# Deal with parameters for the script.
ARGS=$(getopt -o j: --long jobs: -- "$@")
eval set -- "$ARGS"
while :
do
	case "$1" in
		-j | --jobs)
			BUILD_PROCESSES=$2
			shift 2
			;;
		--)
			shift
			break
			;;
		*)
			echo "Internal error!"
			exit 1
			;;
	esac
done

# clear old outputs.
rm -f *.deb
rm -f backup-*.tgz

mainVersion=`cat $VERSION_FILE | awk -F= '/mainVersion/{print $2}' | tr -d '\r'`
minorVersion=`cat $VERSION_FILE | awk -F= '/minorVersion/{print $2}' | tr -d '\r'`
patchVersion=`cat $VERSION_FILE | awk -F= '/fourVersion/{print $2}' | tr -d '\r'`
releaseVersion=`cat $VERSION_FILE | awk -F= '/extra1/{print $2}' | tr -d '\r'`
pkgVersion=$mainVersion.$minorVersion.$patchVersion
pkgRelease=${releaseVersion##*_}

# do compiling.
make clean
make -j$BUILD_PROCESSES $@
if [ $? -ne 0 ]; then
	echo -e "\\033[1;31m"
	echo "Error occured while compiling. Stop!"
	echo -e "\\033[0m"
	exit 1
fi

# build extra open source target.
if [ -d extrabuild ]; then
	echo -e "\\033[1;33m"
	echo "Building some extra open source targets ..."
	echo -e "\\033[0m"
	pushd extrabuild
	. extra-build.sh -j$BUILD_PROCESSES $@
	popd
fi

# make a package.
sudo make uninstall $@
sudo checkinstall --pkgname=$pkgName --pkgversion=$pkgVersion --pkgrelease=$pkgRelease -y --install=no --strip=no
cp ${pkgName}*.deb ${pkgName}.deb

# re-package the rcd.deb as an uncompressed package.
dpkg -X ${pkgName}.deb ${pkgName}_tmp
echo
pushd ${pkgName}_tmp
dpkg -e $TOPDIR/${pkgName}.deb
if [ -d $TOPDIR/DEBIAN/ ]; then
	cp -rf $TOPDIR/DEBIAN/ .
	chmod +x DEBIAN/*
fi
popd
rm -f ${pkgName}.deb
dpkg-deb -b -Znone ${pkgName}_tmp ${pkgName}.deb
rm -rf ${pkgName}_tmp
echo
echo "$pkgName packaging OK! find output: ${pkgName}.deb"
echo
