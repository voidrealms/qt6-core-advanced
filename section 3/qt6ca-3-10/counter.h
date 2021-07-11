#ifndef COUNTER_H
#define COUNTER_H

#include <QRunnable>
#include <QThread>
#include <QDebug>
#include <QMutex>

class Counter : public QRunnable
{
public:
    Counter(QMutex* mutex,int* value);

    // QRunnable interface
public:
    void run();

private:
    int* m_value;
    QMutex* m_mutex;
};

#endif // COUNTER_H
