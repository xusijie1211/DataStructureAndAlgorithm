#!/bin/bash
#

#
# do following to add extra open source build:
# 1. create a dir for the open source. (e.g. x264 in the dir sample)
# 2. put the open source tarfile (e.g. last_x264.tar.bz2) into the new dir.
# 3. create a building script for the open source, named as @dirname@-build.sh (e.g. x264-build.sh)
# 4. add a local.mak & Makefile into the new dir.
# 5. add the new dir name on target.mak, assigning to the @extra_target@ variable.
#

extra_targets=$(awk -F= '/^extra_target/ {print $2}' target.mak)
for target in $extra_targets
do
    echo "Building extra target: $target ..."
    pushd $target
    ./${target}-build.sh $@
    if [ $? -ne 0 ]; then
        echo -e "\\033[1;31m"
        echo "Error occured while building extra target $target. Stop!"
        echo -e "\\033[0m"
        exit 1
    fi
    popd
    echo
done
