#Top Makefile for c++ program
# Copyright (C) 2017 wwwang9001@163.com

export DEBUG_SYMBOLS = TRUE
export PLATFORM = linux
export MOD_SRC_DIR = ./src
MODULES =$(shell ls $(MOD_SRC_DIR))
#MODULES = main tools
ifeq ($(DEBUG_SYMBOLS), TRUE)  
		BUILDDIR = ./build/$(PLATFORM)_dbg
else  
		BUILDDIR = ./build/$(PLATFORM)
endif 

all : $(BUILDDIR) $(MODULES) 

$(BUILDDIR):  
		@echo "    Create directory $@ ..."  
		mkdir -p $(BUILDDIR)/bin $(BUILDDIR)/lib

$(MODULES):
	$(MAKE) -C $(MOD_SRC_DIR)/$@

main: tools

obj:
	@for subdir in $(MODULES);\
	do $(MAKE) -C $(MOD_SRC_DIR)/$$subdir $@;\
	done


clean:
	@for subdir in $(MODULES);\
	do $(MAKE) -C $(MOD_SRC_DIR)/$$subdir $@;\
	done


disclean:
	@for subdir in $(MODULES);\
	do $(MAKE) -C $(MOD_SRC_DIR)/$$subdir $@;\
	done

tags:
	ctags -R

help:  
	@echo "===============A common Makefilefor c programs=============="  
	@echo "Copyright (C) 2017 wwwang9001@163.com"  
	@echo "The following targets aresupport:"  
	@echo  
	@echo " all              - (==make) compile and link"  
	@echo " obj              - just compile, withoutlink"  
	@echo " clean            - clean target"  
	@echo " distclean        - clean target and otherinformation"  
	@echo " tags             - create ctags for vimeditor"  
	@echo " help             - print help information"  
	@echo  
	@echo "To make a target, do 'make[target]'"  
	@echo "========================= Version2.0 ======================="  
   
.PHONY : all clean distclean tags help 
