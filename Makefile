# GNU Make workspace makefile autogenerated by Premake

.NOTPARALLEL:

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug)
  gm_autogit_config = debug
endif
ifeq ($(config),release)
  gm_autogit_config = release
endif

PROJECTS := gm_autogit

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

gm_autogit:
ifneq (,$(gm_autogit_config))
	@echo "==== Building gm_autogit ($(gm_autogit_config)) ===="
	@${MAKE} --no-print-directory -C . -f gm_autogit.make config=$(gm_autogit_config)
endif

clean:
	@${MAKE} --no-print-directory -C . -f gm_autogit.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug"
	@echo "  release"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   gm_autogit"
	@echo ""
	@echo "For more information, see http://industriousone.com/premake/quick-start"