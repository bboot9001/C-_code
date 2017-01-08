
#include "BTThreadPool.h"

BTThreadPool::BTThreadPool() : m_pool_size(DEFAULT_POOL_SIZE)
{

}

BTThreadPool::BTThreadPool(int pool_size) : m_pool_size(pool_size)
{

}

BTThreadPool::~BTThreadPool()
{
    if(m_pool_state != STOPPED)
    {
        destroy_threadpool();
    }
}

extern "C"
void* start_thread(void* arg)
{
  BTThreadPool* tp = (BTThreadPool*) arg;
  tp->execute_thread();
  return NULL;
}

int     BTThreadPool::initialize_threadpool()
{
    m_pool_state = STARTED;
    int ret = -1;
    for(int i = 0; i < m_pool_size; ++i)
    {
        pthread_t tid;
        ret = pthread_create(&tid, NULL, start_thread, (void*)this);
        if(ret != 0)
        {
            cerr <<"pthread_create() failed:"<< ret <<endl;
            return -1;
        }
        m_threads.push_back(tid);
    }

    return 0;
}

int     BTThreadPool::destroy_threadpool()
{
    m_task_mutex.lock();
    m_pool_state = STOPPED;
    m_task_mutex.unlock();

    m_task_cond_var.broadcast();

    int ret = -1;
    for(int i = 0; i < m_pool_size ;++i)
    {
        void* result;
        ret = pthread_join(m_threads[i],&result);
        m_task_cond_var.broadcast();
    }
    return 0;
}

void *BTThreadPool::execute_thread()
{
    BTTask *task = NULL;
    //cout << "Starting thread " << pthread_self() << endl;
    while (true)
    {
        // Try to pick a task
        //cout << "Locking: " << pthread_self() << endl;
        m_task_mutex.lock();

        // We need to put pthread_cond_wait in a loop for two reasons:
        // 1. There can be spurious wakeups (due to signal/ENITR)
        // 2. When mutex is released for waiting, another thread can be waken up
        //    from a signal/broadcast and that thread can mess up the condition.
        //    So when the current thread wakes up the condition may no longer be
        //    actually true!
        while ((m_pool_state != STOPPED) && (m_tasks.empty()))
        {
            // Wait until there is a task in the queue
            // Unlock mutex while wait, then lock it back when signaled
            //cout << "Unlocking and waiting: " << pthread_self() << endl;
            m_task_cond_var.wait(m_task_mutex.get_mutex_ptr());
            //cout << "Signaled and locking: " << pthread_self() << endl;
        }

        // If the thread was woken up to notify process shutdown, return from here
        if (m_pool_state == STOPPED)
        {
           // cout << "Unlocking and exiting: " << pthread_self() << endl;
            m_task_mutex.unlock();
            pthread_exit(NULL);
        }

        task = m_tasks.front();
        m_tasks.pop_front();
        //cout << "Unlocking: " << pthread_self() << endl;
        m_task_mutex.unlock();

        //cout << "Executing thread " << pthread_self() << endl;
        // execute the task
        (*task)(); // could also do task->run(arg);
        //cout << "Done executing thread " << pthread_self() << endl;
        delete task;
    }
    return NULL;
}

int     BTThreadPool::add_task(BTTask *task)
{
    m_task_mutex.lock();

    // TODO: put a limit on how many tasks can be added at most
    m_tasks.push_back(task);

    m_task_cond_var.signal(); // wake up one thread that is waiting for a task to be available

    m_task_mutex.unlock();

    return 0;
}