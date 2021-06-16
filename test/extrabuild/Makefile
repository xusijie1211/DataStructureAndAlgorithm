#
# target modules Makefile
#
include $(top_srcdir)/env.mak

#
# ALL target
#
.PHONY: all
all: build

# target TOPDIR
TARGET_TOPDIR := $(shell pwd)

# ================ Modified Area START ================ #

include $(TARGET_TOPDIR)/target.mak

# ================= Modified Area END ================= #

.PHONY: build
build:

.PHONY: clean
clean: $(patsubst %, _c_%, $(extra_target))
$(patsubst %, _c_%, $(extra_target)): 
	$(MAKE) -C $(TARGET_TOPDIR)/$(patsubst _c_%,%,$@) clean

.PHONY: install
install: $(patsubst %, _inst_%, $(extra_target))
$(patsubst %, _inst_%, $(extra_target)): 
	$(MAKE) -C $(TARGET_TOPDIR)/$(patsubst _inst_%,%,$@) install

.PHONY: uninstall
uninstall: $(patsubst %, _uninst_%, $(extra_target))
$(patsubst %, _uninst_%, $(extra_target)): 
	$(MAKE) -C $(TARGET_TOPDIR)/$(patsubst _uninst_%,%,$@) uninstall

.PHONY: gcov_prepare
gcov_prepare: