#!/bin/bash
#

. $(find . -name "BUILD_PKG.sh" -print)

if [ ! -f $VERSION_FILE ]; then
	cat > $VERSION_FILE << EOF
[LINUX-rcd.${pkgName}]
ruijie.product=rcd.${pkgName}
ruijie.rcd.${pkgName}.mainVersion=1
ruijie.rcd.${pkgName}.minorVersion=0
ruijie.rcd.${pkgName}.threeVersion=0
ruijie.rcd.${pkgName}.extra1=_R1
ruijie.rcd.${pkgName}.fourVersion=1
ruijie.rcd.${pkgName}.extra2=
ruijie.rcd.${pkgName}.buildDate=2018-05-01
EOF
fi
VERSION_RELEASE=$(cat $VERSION_FILE | awk -F= '/extra1/{print $2}' | tr -d '\r')
VERSION_RELEASE=${VERSION_RELEASE##*_}

if [ -n "$1" ]; then
	if [ "$1" = "revert" ]; then
		git checkout -- $VERSION_FILE
		exit 0
	fi
	if echo $1 | grep -q '\.'; then
		mainVersion=$(echo $1 | awk -F. '{print $1}')
		minorVersion=$(echo $1 | awk -F. '{print $2}')
		patchVersion=$(echo $1 | awk -F. '{print $3}')
	else
		mainVersion=$(cat $VERSION_FILE | awk -F= '/mainVersion/{print $2}' | tr -d '\r')
		minorVersion=$(cat $VERSION_FILE | awk -F= '/minorVersion/{print $2}' | tr -d '\r')
		patchVersion=$1
	fi
else
	mainVersion=$(cat $VERSION_FILE | awk -F= '/mainVersion/{print $2}' | tr -d '\r')
	minorVersion=$(cat $VERSION_FILE | awk -F= '/minorVersion/{print $2}' | tr -d '\r')
	patchVersion=$(cat $VERSION_FILE | awk -F= '/fourVersion/{print $2}' | tr -d '\r')
fi
if [ -n "$2" ]; then
	release_ver=$2
	VERSION_RELEASE=${release_ver##*_}
fi
buildDate=$(date +%F)
HEADcommit=$(git log -1 | awk '/^commit/ {print $2}')
curBranch=$(git branch | awk '/^\*/ {print $2}')

cat > $VERSION_FILE.$$ << EOF
[LINUX-rcd.${pkgName}]
ruijie.product=rcd.${pkgName}
ruijie.rcd.${pkgName}.mainVersion=$mainVersion
ruijie.rcd.${pkgName}.minorVersion=$minorVersion
ruijie.rcd.${pkgName}.threeVersion=0
ruijie.rcd.${pkgName}.extra1=_$VERSION_RELEASE
ruijie.rcd.${pkgName}.fourVersion=$patchVersion
ruijie.rcd.${pkgName}.extra2=
ruijie.rcd.${pkgName}.buildDate=$buildDate
ruijie.rcd.${pkgName}.buildHEAD=$HEADcommit
ruijie.rcd.${pkgName}.buildBranch=$curBranch
EOF

mv $VERSION_FILE.$$ $VERSION_FILE
cat $VERSION_FILE
