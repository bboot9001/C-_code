#top Makefile for lib
#Copyright (C) 2017 wwwang9001@163.com

ifeq ($(DEBUG_SYMBOLS), TRUE)
CFLAGS += -g -Wall -Werror -O0
else
CFLAGS += -Wall -Werror -O2
endif
CPPFLAGS += -I.-I./inc -I ../../include
LDFLAGS +=-lpthread -L../../lib  -ltool
SRC = $(wildcard src/*.cpp)
# SRC_OBJ = $(patsubst %.cpp, %.o, $(wildcard *.cpp)) 
SRC_OBJ = $(SRC:.cpp=.o)
SRC_BIN = target_bin
CC = g++

all:$(SRC_BIN)

$(SRC_BIN): $(SRC_OBJ)
	$(CC) -o ../../bin/$@ $^ $(LDFLAGS) $(CFLAGS)

obj:$(SRC_OBJ)

clean:
	$(RM)  $(SRC_OBJ) $(SRC_BIN) $(SRC_BIN).exe

distclean:  
	$(RM) $(SRC_OBJ) $(SRC_BIN) $(SRC_BIN).exe tags *~

.PHONY : all obj clean disclean  
