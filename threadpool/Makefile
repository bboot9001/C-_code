target_bin:main.o BTCond.o BTMutex.o BTTask.o BTThreadPool.o
	g++ -o target_ThreadPool  main.o BTCond.o BTMutex.o BTTask.o BTThreadPool.o -lpthread

main.o: main.cpp
	 g++ -c main.cpp

BTCond.o: BTCond.cpp
	g++ -c BTCond.cpp

BTMutex.o: BTMutex.cpp
	g++ -c BTMutex.cpp

BTThreadPool.o: BTThreadPool.cpp
	g++ -c BTThreadPool.cpp

BTTask.o: BTTask.cpp
	g++ -c BTTask.cpp

clean:
	rm *.o target_ThreadPool
