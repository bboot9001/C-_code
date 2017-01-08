#ifndef _H_BTMUTEX_H_
#define _H_BTMUTEX_H_
#include <pthread.h>

class BTMutex
{
public:
    BTMutex();
    ~BTMutex();

public:
    void lock();
    void unlock();
    pthread_mutex_t* get_mutex_ptr();

private:
    pthread_mutex_t     m_lock;
    volatile bool       is_locked;
};
#endif//_H_BTMUTEX_H_