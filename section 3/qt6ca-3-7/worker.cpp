#include "worker.h"

Worker::Worker(QObject *parent) : QObject(parent)
{

}

void Worker::work()
{
    for(int i = 0; i < 10; i++)
    {
        qInfo() << "Work" << i << QThread::currentThread();
        QThread::currentThread()->msleep(1000);
    }
}
