#ifndef _H_BTTHREADPOOL_H_
#define _H_BTTHREADPOOL_H_

#include <pthread.h>
#include <unistd.h>
#include "BTMutex.h"
#include "BTCond.h"
#include "BTTask.h"
#include "Global.h"
#include <string.h>
#include <vector>
#include <deque>
#include <errno.h>
#include "stdio.h"
#include <iostream>
using namespace std;

class BTThreadPool
{
public:
    BTThreadPool();
    BTThreadPool(int pool_size);
    ~BTThreadPool();

public:
    int     initialize_threadpool();
    int     destroy_threadpool();
    void*   execute_thread();
    int     add_task(BTTask* task);

private:
    int                         m_pool_size;
    BTMutex                     m_task_mutex;
    BTCond                      m_task_cond_var;
    std::vector<pthread_t>      m_threads;
    std::deque<BTTask*>         m_tasks;
    volatile int                m_pool_state;

};
#endif//_H_BTTHREADPOOL_H_