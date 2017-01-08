#include "BTTask.h"


BTTask::BTTask(void (*fn_ptr)(void*), void* arg) : m_fn_ptr(fn_ptr) , m_arg(arg)
{

}

BTTask::~BTTask()
{

}

void BTTask::run()
{
    (*m_fn_ptr)(m_arg);
}

void BTTask::operator()()
{
    (*m_fn_ptr)(m_arg);
    if(m_arg != NULL)
    {
        delete m_arg;
    }
}