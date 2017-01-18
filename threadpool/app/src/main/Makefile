#top Makefile for lib
#Copyright (C) 2017 wwwang9001@163.com

SRC_BASE = ../..
CFLAGS += 
CPPFLAGS += -I.-I./inc -I $(SRC_BASE)/include
LDFLAGS +=-lpthread -L$(SRC_BASE)/libs  -ltool
SRC_FILES = $(wildcard src/*.cpp)
# SRC_OBJ = $(patsubst %.cpp, %.o, $(wildcard *.cpp)) 
SRC_OBJ = $(SRC_FILES:.cpp=.o)
SRC_BIN = target_demo
include $(SRC_BASE)/Makefile.rule