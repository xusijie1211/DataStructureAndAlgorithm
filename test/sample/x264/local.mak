#
# Install only Makefile variables definition.
# Modified area: add install actions here to do compiling.
#

# extra build source dir.
extra_srcdir := x264-snapshot-20141218-2245

.PHONY: extra-clean
extra-clean:
	rm -rf $(extra_srcdir)

#
# extra intstall target.
#
.PHONY: install_extra
install_extra:
	@echo "install extra files..."
	$(MAKE) -C $(extra_srcdir) install

.PHONY: uninstall_extra
uninstall_extra:
	@echo "uninstall extra files..."
	$(MAKE) -C $(extra_srcdir) uninstall
