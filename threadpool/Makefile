CFLAGS += -g -Wall-Werror -O2
CPPFLAGS += -I.-I./inc 
LDFLAGS +=-lpthread  
SRC = $(wildcard *.cpp)
# SRC_OBJ = $(patsubst %.cpp, %.o, $(wildcard *.cpp)) 
SRC_OBJ = $(SRC:.cpp=.o)
SRC_BIN = target_ThreadPool
CC = g++
$(SRC_BIN): $(SRC_OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	$(RM)  $(SRC_OBJ) $(SRC_BIN)
