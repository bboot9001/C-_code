#ifndef _H_BTCOND_H_
#define _H_BTCOND_H_
#include <pthread.h>

class BTCond
{
public:
    BTCond();
    ~BTCond();

public:
    void wait(pthread_mutex_t* mutex);
    void signal();
    void broadcast();

private:
    pthread_cond_t      m_bt_cond;
};


#endif//_H_BTCOND_H_