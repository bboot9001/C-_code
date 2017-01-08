SRC_OBJ = main.o BTCond.o BTMutex.o BTTask.o BTThreadPool.o
SRC_BIN = target_ThreadPool
$(SRC_BIN): $(SRC_OBJ)
	g++ -o target_ThreadPool  main.o BTCond.o BTMutex.o BTTask.o BTThreadPool.o -lpthread

clean:
	rm  $(SRC_OBJ) $(SRC_BIN)
