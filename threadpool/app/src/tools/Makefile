#top Makefile for lib
#Copyright (C) 2017 wwwang9001@163.com
CFLAGS += -g -Wall-Werror -O2
CPPFLAGS += -I.-I ./inc -I../../include
LDFLAGS +=-lpthread  
SRC = $(wildcard src/*.cpp)
# SRC_OBJ = $(patsubst %.cpp, %.o, $(wildcard *.cpp)) 
SRC_OBJ = $(SRC:.cpp=.o)
SRC_LIB = libtool.a
CC = g++

all:$(SRC_LIB)

$(SRC_LIB): $(SRC_OBJ)
	$(AR) rcs ../../lib/$@ $^

obj:$(SRC_OBJ)

clean:
	$(RM)  $(SRC_OBJ) $(SRC_LIB)

distclean:  
	$(RM) $(SRC_OBJ) $(SRC_LIB) tags *~

.PHONY : all obj clean disclean  
