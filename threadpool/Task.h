#ifndef  _H_TASK_H_
#define  _H_TASK_H_
#include <pthread.h>

class Task
{
public:
    Task(void (*fn_ptr)(void*), void* arg);
    ~Task();

public:
    void operator()();
    void run();

private:
    void    (*m_fn_ptr)(void* );
    void*   m_arg;
};



#endif//_H_TASK_H_