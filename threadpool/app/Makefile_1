#top Makefile for app
#Copyright (C) 2017 wwwang9001@163.com

all:
	$(MAKE) -C src/tools
	$(MAKE) -C src/main

tags:
	ctags -R

help:  
	@echo "===============A common Makefile for cprograms=============="  
	@echo "Copyright (C) 2017  bboot9001 wwwang9001@163.com"  
	@echo "The following targets are support:"  
	@echo  
	@echo " all             - (==make) compile and link"  
	@echo " obj             - just compile, without link"  
	@echo " clean           - clean target"  
	@echo " distclean       - clean target and otherinformation"  
	@echo " tags            - create ctags for vim editor"  
	@echo " help            - print help information"  
	@echo  
	@echo "To make a target, do 'make [target]'"  
	@echo "========================= Version 1.1======================="
obj:
	$(MAKE) -C src/tools obj
	$(MAKE) -C src/main obj

clean:
	$(MAKE) -C src/tools clean
	$(MAKE) -C src/main clean

distclean:
	$(MAKE) -C src/tools distclean
	$(MAKE) -C src/main distclean

.PHONY : all clean tags distclean  help
