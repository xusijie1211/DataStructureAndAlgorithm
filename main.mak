#
# IDV client Top Makefile variables definitions.
# Modified area: add new modules here.
#

# Client header files.
# RCLIB_MPATH :=
# ADD_CFLAGS += $(patsubst %,-I$(top_srcdir)/%,$(RCLIB_MPATH))

# Modules common extra FLAGS.
EXTRA_CFLAGS :=
EXTRA_LDFLAGS :=

# Extra Libs to be installed into RCD system.
extra_alibs :=
extra_solibs :=

# All the target applications to be compiled.
# Install only target.
#target_app += version extrabuild

# All the target libraries to be compiled.
target_lib += sample/libtree/libtrees
target_lib += sample/libtree/libprint_trees
target_lib += sample/libtree/libbisort_trees
target_lib += sample/libtree/libAVLTrees

#
# for GCOV output PRELOAD
# Usage:
#   LD_PRELOAD=$(install_libdir)/lib$(GCOV_OUTLIB).so cmdline
# add signal handler to lead cmd calling __gcov_flush() after killed or crash.
#

# target sample:
target_app := sample/Trees
target_app := sample
#target_app := Trees/hello_copy


