SRC_OBJ = main.o BTCond.o BTMutex.o BTTask.o BTThreadPool.o
SRC_BIN = target_ThreadPool
CC = g++
$(SRC_BIN): $(SRC_OBJ)
	$(CC) -o $@ $^ -lpthread

clean:
	$(RM)  $(SRC_OBJ) $(SRC_BIN)
