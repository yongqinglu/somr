###############################################################################
#
# (c) Copyright IBM Corp. 2015, 2016
#
#  This program and the accompanying materials are made available
#  under the terms of the Eclipse Public License v1.0 and
#  Apache License v2.0 which accompanies this distribution.
#
#      The Eclipse Public License is available at
#      http://www.eclipse.org/legal/epl-v10.html
#
#      The Apache License v2.0 is available at
#      http://www.opensource.org/licenses/apache2.0.php
#
# Contributors:
#    Multiple authors (IBM Corp.) - initial implementation and documentation
###############################################################################

###
### Default Target
###

all:

help:
	@echo "This makefile is used to configure OMR before being built.  You should specify the following"
	@echo "variables before using this script:"
	@echo "SPEC      Should match the current platform (e.g. SPEC=linux_x86-64)"
	@echo "OMRGLUE   OMRGLUE should be set to the path to the OMR glue files (e.g OMRGLUE=\$$PWD/example/glue)"
	@echo "CONFIG_INCL_DIR"
	@echo "          The path to makefiles which are included into this makefile."
	@echo "          Defaults to: \$$(OMRGLUE)/configure_includes"
	@echo ""
	@echo "This makefile supports the following targets:"
	@echo "help      Display this help message."
	@echo "all       Run configure."
	@echo "clean     Delete header files and makefiles generated by configure."
	@echo "distclean Delete generated header files and makefiles, and other byproducts of running configure,"
	@echo "          including caches and downloaded files."

.PHONY: all help

# Remove all built-in rules
.SUFFIXES:

###
### SPEC Specific Configure Arguments
###

ifdef OMRGLUE
  # Do not set CONFIG_INCL_DIR if it is set in the environment.
  CONFIG_INCL_DIR ?= $(firstword $(OMRGLUE))/configure_includes
endif

# If CONFIG_INCL_DIR is defined, we include platform specfic makefiles
# from that directory. These makefiles are expected to add extra configure
# arguments to the variable CONFIGURE_ARGS.
ifdef CONFIG_INCL_DIR
HAS_AUTOCONF ?= no
CONFIGURE_ARGS :=
ifneq (,$(findstring aix_ppc,$(SPEC)))
  include $(CONFIG_INCL_DIR)/configure_aix_ppc.mk
endif
ifneq (,$(findstring linux_390,$(SPEC)))
  include $(CONFIG_INCL_DIR)/configure_linux_390.mk
endif
ifneq (,$(findstring linux_arm,$(SPEC)))
  include $(CONFIG_INCL_DIR)/configure_linux_arm.mk
endif
ifneq (,$(findstring linux_ppc,$(SPEC)))
  include $(CONFIG_INCL_DIR)/configure_linux_ppc.mk
endif
ifneq (,$(findstring linux_x86,$(SPEC)))
  include $(CONFIG_INCL_DIR)/configure_linux_x86.mk
endif
ifneq (,$(findstring osx,$(SPEC)))
  include $(CONFIG_INCL_DIR)/configure_osx.mk
endif
ifneq (,$(findstring win_x86,$(SPEC)))
  include $(CONFIG_INCL_DIR)/configure_win_x86.mk
  # OMRTODO: this is J9 buildfarm specific code.
  export PATH:=$(DEV_TOOLS)\jtc-toolchain\java7\windows\mingw-msys\msys\1.0\bin;$(PATH)
endif
ifneq (,$(findstring zos_390,$(SPEC)))
  include $(CONFIG_INCL_DIR)/configure_zos_390.mk
endif
endif # ifdef CONFIG_INCL_DIR
CONFIGURE_ARGS += $(EXTRA_CONFIGURE_ARGS)

###
### Check Environment Variables
###

# This makefile depends on environment variables.  If any of them are changed,
# we need to re-run configure.
check-environment-variables:
ifndef SPEC
	$(error SPEC undefined.)
endif
ifneq ("$(SPEC)","$(if $(wildcard SPEC),$(shell cat SPEC),)")
	@echo $(SPEC) > SPEC
endif
ifndef OMRGLUE
	$(error OMRGLUE is unset.)
endif

SPEC: check-environment-variables

clean-environment-variables:
	-$(RM) SPEC

clean: clean-environment-variables

.PHONY: check-environment-variables clean-environment-variables

###
### Configure Rules
###

define CONFIGURE_RECIPE
sh configure --disable-auto-build-flag 'OMRGLUE=$(OMRGLUE)' 'SPEC=$(SPEC)' $(CONFIGURE_ARGS)
# Force the timestamps of unchanged files to be updated
touch $(CONFIGURE_OUTPUT_FILES)
endef

CONFIGURE_DEPENDENCIES := SPEC config.guess config.sub configure toolconfig/configure
CONFIGURE_OUTPUT_FILES := include_core/omrcfg.h include_core/omrversionstrings.h omrmakefiles/omrcfg.mk omrmakefiles/configure.mk omrmakefiles/toolconfigure.mk CONFIGURE_SENTINEL_FILE
CONFIGURE_INPUT_FILES := include_core/omrcfg.h.in include_core/omrversionstrings.h.in omrmakefiles/configure.mk.in omrmakefiles/toolconfigure.mk.in
CONFIGURE_BYPRODUCTS := config.cache config.status config.log autom4te.cache toolconfig/config.cache toolconfig/config.status toolconfig/config.log toolconfig/autom4te.cache

all: check-environment-variables CONFIGURE_SENTINEL_FILE

configure: configure.ac
ifeq ($(HAS_AUTOCONF),1)
	autoconf
else
	@echo "WARNING: autoconf needs to be re-run in $$PWD.  You should do this by hand, or set HAS_AUTOCONF=1 to have this makefile do it for you."
endif

toolconfig/configure: toolconfig/configure.ac
ifeq ($(HAS_AUTOCONF),1)
	cd toolconfig && autoconf
else
	@echo "WARNING: autoconf needs to be re-run in $$PWD/toolconfig.  You should do this by hand, or set HAS_AUTOCONF=1 to have this makefile do it for you."
endif

config.guess:
	curl -o config.guess "http://git.savannah.gnu.org/gitweb/?p=config.git;a=blob_plain;f=config.guess;hb=HEAD"

config.sub:
	curl -o config.sub "http://git.savannah.gnu.org/gitweb/?p=config.git;a=blob_plain;f=config.sub;hb=HEAD"

# Since configure has many output files, we are using a 'sentinel file' to make
# sure that this recipe is only executed once when running configure in parallel.
# This file is created by the CONFIGURE_RECIPE command.
CONFIGURE_SENTINEL_FILE: $(CONFIGURE_DEPENDENCIES) $(CONFIGURE_INPUT_FILES)
	$(CONFIGURE_RECIPE)

clean:
	-$(RM) $(CONFIGURE_OUTPUT_FILES) config.cache

distclean: clean
	-$(RM) $(CONFIGURE_DEPENDENCIES)
	-$(RM) -r $(CONFIGURE_BYPRODUCTS)

.PHONY: clean distclean
