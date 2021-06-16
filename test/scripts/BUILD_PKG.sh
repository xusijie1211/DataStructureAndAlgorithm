#!/bin/bash
#

curdirname=$(basename $PWD)
if [ "$curdirname" = "scripts" ]; then
    cd ..
fi

# We start app building with project top dir.
TOPDIR=$PWD

# package name & version file path.
pkgName=$(awk '/^PACKAGE_TARGET/ {print $3}' $TOPDIR/env.mak | tr '[A-Z]' '[a-z]' | sed 's/[_-]//g')
VERSION_FILE=$TOPDIR/version/version_${pkgName}.ini
