#include "counter.h"

Counter::Counter(QMutex *mutex, int *value)
{
    m_value = value;
    m_mutex = mutex;
}


void Counter::run()
{
    //Wait until we can do stuff...


    //Our code here
    QThread::currentThread()->msleep(50);

    QMutexLocker locker(m_mutex);
    *m_value = *m_value + 1;
    qInfo() << *m_value << QThread::currentThread();


}
