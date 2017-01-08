
#include <iostream>
#include "BTThreadPool.h"

using namespace std;

const int MAX_TASKS = 20000;

void hello(void* arg)
{
  int* x = (int*) arg;
  sleep(2);
  cout << "Hello " << *x << endl;
}

int main(int argc, char* argv[])
{
  BTThreadPool tp(10000);
  int ret = tp.initialize_threadpool();
  if (ret == -1) {
    cerr << "Failed to initialize thread pool!" << endl;
    return 0;
  }

  for (int i = 0; i < MAX_TASKS; i++) {
    int* x = new int();
    *x = i+1;
    BTTask* t = new BTTask(&hello, (void*) x);
    tp.add_task(t);
  }

  sleep(2);

  tp.destroy_threadpool();

  // TODO: delete worker objects

  cout << "Exiting app..." << endl;

  return 0;
}