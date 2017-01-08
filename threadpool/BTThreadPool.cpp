
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

extern "C" void* start_thread(void* arg)
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
            std::cerr <<"pthread_create() failed:"<< ret <<endl;
            return -1;
        }
        m_threads.push_back(tid);
    }
    std::cout<<m_pool_size<<"thread created by the thread pool"<<endl;
    return 0;
}

int     BTThreadPool::destroy_threadpool()
{
    m_task_mutex.lock();
    m_pool_state = STOPPED;
    m_task_mutex.unlock();

    m_task_cond_var.broadcast();
    std::cout<<"Broadcasting Stop signal to all threads..."<<endl;

    int ret = -1;
    for(int i = 0; i < m_pool_size ;++i)
    {
        void* result;
        ret = pthread_join(m_threads[i],&result);
        std::cout<<"pthread_join() return "<<ret <<":"<<strerror(errno)<<endl;
        m_task_cond_var.broadcast();
    }
    std::cout<<m_pool_size<<"threads exited from the thread pool"<<endl;
    return 0;
}

void *BTThreadPool::execute_thread()
{
    BTTask *task = NULL;
    std::cout << "Starting thread " << pthread_self() << endl;
    while (true)
    {
        std::cout << "Locking: " << pthread_self() << endl;
        m_task_mutex.lock();

        while ((m_pool_state != STOPPED) && (m_tasks.empty()))
        {
            std::cout << "Unlocking and waiting: " << pthread_self() << endl;
            m_task_cond_var.wait(m_task_mutex.get_mutex_ptr());
            std::cout << "Signaled and locking: " << pthread_self() << endl;
        }

        if (m_pool_state == STOPPED)
        {
            std::cout << "Unlocking and exiting: " << pthread_self() << endl;
            m_task_mutex.unlock();
            pthread_exit(NULL);
        }

        task = m_tasks.front();
        m_tasks.pop_front();
        std::cout << "Unlocking: " << pthread_self() << endl;
        m_task_mutex.unlock();

        std::cout << "Executing thread " << pthread_self() << endl;
        // execute the task
        (*task)(); // could also do task->run(arg);
        std::cout << "Done executing thread " << pthread_self() << endl;
        delete task;
    }
    return NULL;
}

int     BTThreadPool::add_task(BTTask *task)
{
    m_task_mutex.lock();
    m_tasks.push_back(task);

    m_task_cond_var.signal(); 

    m_task_mutex.unlock();

    return 0;
}