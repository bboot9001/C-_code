#ifndef  _H_BTTASK_H_
#define  _H_BTTASK_H_
#include <pthread.h>

class BTTask
{
public:
    BTTask(void (*fn_ptr)(void*), void* arg);
    ~BTTask();

public:
    void operator()();
    void run();

private:
    void    (*m_fn_ptr)(void* );
    void*   m_arg;
};



#endif//_H_BTTASK_H_