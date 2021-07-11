#include "consumer.h"


Consumer::Consumer(QMutex *mutex, QWaitCondition *valueReady, int *value, QObject *parent)
{
    Q_UNUSED(parent);
    m_mutex = mutex;
    m_valueReady = valueReady;
    m_value = value;
}

void Consumer::run()
{
    qInfo() << "Consumer running";
    m_mutex->lock();
    qInfo() << "Consumer locked the mutex";
    if(*m_value == 0)
    {
        qInfo() << "Consumer is waiting on a value";
        m_valueReady->wait(m_mutex);
    }

    qInfo() << "Consuming:" << *m_value;
}
