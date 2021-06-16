#
# IDV Client modules main Makefile
#
include $(top_srcdir)/env.mak

#
# ALL target
#
all: do-it-all

# Module root dir.
APP_TOPDIR := $(shell pwd)

# ================ Modified Area START ================ #

include $(APP_TOPDIR)/local.mak

# ================= Modified Area END ================= #

extra_srcdir := $(wildcard $(extra_srcdir))

ifdef QUIET
Q:=@
else
Q:=
endif

.PHONY: do-it-all

.PHONY: install
install:
	$Q$(MAKE) install_extra

.PHONY: uninstall
uninstall:
	$Q$(MAKE) uninstall_extra

.PHONY: clean
clean: $(patsubst %, _c_%, $(extra_srcdir))
	$Q$(MAKE) extra-clean

$(patsubst %, _c_%, $(extra_srcdir)):
	$(MAKE) -C $(extra_srcdir) clean
