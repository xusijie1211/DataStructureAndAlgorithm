#
# Install only Makefile variables definition.
# Modified area: add install actions here to do compiling.
#

PACKAGE_NAME := $(shell echo $(PACKAGE_TARGET) | tr '[A-Z]' '[a-z]' | sed 's/[_-]//g')

#
# extra intstall target.
#
.PHONY: install_extra
install_extra:
	@echo "install extra files..."
	mkdir -p $(install_confdir)
	cp -f $(APP_TOPDIR)/version_$(PACKAGE_NAME).ini $(install_confdir)

.PHONY: uninstall_extra
uninstall_extra:
	@echo "uninstall extra files..."
	rm -f $(install_confdir)/version_$(PACKAGE_NAME).ini
