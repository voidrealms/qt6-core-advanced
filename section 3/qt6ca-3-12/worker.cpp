#include "worker.h"


Worker::Worker(QSemaphore *sema, QList<int> *values, QObject *parent)
{
    m_sema = sema;
    m_values = values;
}

void Worker::run()
{
    qInfo() << "Run" << QThread::currentThread();
    int max = QRandomGenerator::global()->bounded(1,m_values->size());

    qInfo() << "Acquiring" << max << QThread::currentThread();
    m_sema->acquire(max);

    qInfo() << "Acquired" << m_sema->available() << QThread::currentThread();
    for(int i = 0; i < max; i++)
    {
        qInfo() << "Modify" << i << QThread::currentThread();
        int value = QRandomGenerator::global()->bounded(100);
        m_values->replace(i,value);
        QThread::currentThread()->msleep(250);
    }

    qInfo() << "Release" << max << QThread::currentThread();
    m_sema->release(max);

}
