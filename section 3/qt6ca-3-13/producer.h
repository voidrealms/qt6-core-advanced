#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>
#include <QWaitCondition>
#include <QMutex>
#include <QThread>
#include <QDebug>
#include <QRandomGenerator>

class Producer : public QObject
{
    Q_OBJECT
public:
    explicit Producer(QMutex *mutex,QWaitCondition *valueReady,int *value,QObject *parent = nullptr);

signals:

public slots:
    void run();

private:
    QMutex *m_mutex;
    QWaitCondition *m_valueReady;
    int *m_value;
};

#endif // PRODUCER_H
