#include "BTCond.h"

BTCond::BTCond()
{
    pthread_cond_init(&m_bt_cond, NULL);
}

BTCond::~BTCond()
{
    pthread_cond_destroy(&m_bt_cond);
}

void BTCond::wait(pthread_mutex_t* mutex)
{
    pthread_cond_wait(&m_bt_cond, mutex);
}

void BTCond::signal()
{
    pthread_cond_signal(&m_bt_cond);
}

void BTCond::broadcast()
{
    pthread_cond_broadcast(&m_bt_cond);
}