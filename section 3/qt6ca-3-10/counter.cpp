#include "counter.h"

Counter::Counter(QMutex *mutex, int *value)
{
    m_value = value;
    m_mutex = mutex;
}


void Counter::run()
{
    //Wait until we can do stuff...

    m_mutex->lock(); //We will wait until we can lock!

    //Our code here
    QThread::currentThread()->msleep(50);
    *m_value = *m_value + 1;
    qInfo() << *m_value << QThread::currentThread();

    m_mutex->unlock(); //Other threads can lock
}
