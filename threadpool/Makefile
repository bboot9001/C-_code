CFLAGS += -g -Wall-Werror -O2
CPPFLAGS += -I.-I./inc 
LDFLAGS +=-lpthread  
SRC = $(wildcard *.cpp)
# SRC_OBJ = $(patsubst %.cpp, %.o, $(wildcard *.cpp)) 
SRC_OBJ = $(SRC:.cpp=.o)
SRC_BIN = target_ThreadPool
CC = g++

all:$(SRC_BIN)

$(SRC_BIN): $(SRC_OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

obj:$(SRC_OBJ)

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

clean:
	$(RM)  $(SRC_OBJ) $(SRC_BIN) $(SRC_BIN).exe

distclean:  
	$(RM) $(SRC_OBJ) $(SRC_BIN) $(SRC_BIN).exe tags *~
