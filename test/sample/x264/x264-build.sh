#!/bin/bash
#

tar -jxf last_x264.tar.bz2
cd x264-snapshot-20141218-2245
./configure --enable-shared --prefix=/usr
make $@
