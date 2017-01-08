#include "BTMutex.h"

BTMutex::BTMutex()
{
    pthread_mutex_init(&m_lock, NULL);
    is_locked = false;
}

BTMutex::~BTMutex()
{
    while(is_locked);
    unlock();
    pthread_mutex_destroy(&m_lock);
}

void BTMutex::lock()
{
    pthread_mutex_lock(&m_lock);
    is_locked  = true;
}

void BTMutex::unlock()
{
    is_locked  = false;
    pthread_mutex_unlock(&m_lock); 
}

pthread_mutex_t* BTMutex::get_mutex_ptr()
{
    return &m_lock;
}