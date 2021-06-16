#
# env.mak
# Copyright (C)2017 Ruijie Network Inc. All rights reserved.
# Author: yejx@ruijie.com.cn
#
# IDV Client compiling environment definition.
#

# Tools.
CC      := gcc
CPP     := g++
LD      := ld
AR      := ar
NM      := nm
OBJDUMP := objdump

# GCOV Tools.
LCOV	:= $(top_srcdir)/scripts/lcov-1.13/bin/lcov
GENHTML	:= $(top_srcdir)/scripts/lcov-1.13/bin/genhtml

export CC CPP LD AR NM OBJDUMP

#
# Package app name
# Package output file name, that will be created as a package with .deb
# Package name can only be the lowercase charaters.
#
PACKAGE_TARGET = app
PACKAGE_CONFDIR = $(PACKAGE_TARGET)

common_headerdir := $(top_srcdir)/include
extra_libdir := $(top_srcdir)/extralib

install_dir := /usr
install_sysconf := /etc
install_extradir := $(install_sysconf)/$(PACKAGE_CONFDIR)

install_bindir := $(install_dir)/bin
install_libdir := $(install_dir)/lib

install_resdir := $(install_extradir)/res
install_confdir := $(install_extradir)
install_scriptdir := $(install_extradir)/scripts

# Basic compiling options.
BUILD_CFLAGS := -Os -Wall -g
BUILD_LDFLAGS := -Os -g

# GCOV compiling options.
GCOV_FLAGS := -fprofile-arcs -ftest-coverage

GCOV_INFO := $(PACKAGE_TARGET).info
GCOV_OUTPUT := $(PACKAGE_TARGET)_coverage
GCOV_OUTLIB := gcov_out
