#include "producer.h"


Producer::Producer(QMutex *mutex, QWaitCondition *valueReady, int *value, QObject *parent)
{
    Q_UNUSED(parent);
    m_mutex = mutex;
    m_valueReady = valueReady;
    m_value = value;
}

void Producer::run()
{
    qInfo() << "Producer running";
    QThread::currentThread()->msleep(3000);

    m_mutex->lock();
    qInfo() << "Producer creating value";
    *m_value = QRandomGenerator::global()->bounded(1000);
    qInfo() << "Producer waking up consumer";
    m_mutex->unlock();

    m_valueReady->wakeAll();

}
