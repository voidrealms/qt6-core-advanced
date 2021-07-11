#include "worker.h"

Worker::Worker(QObject *parent) : QObject(parent)
{
    qInfo() << this << "Constructed on " << QThread::currentThread();
    connect(&timer,&QTimer::timeout,this, &Worker::timeout);
    timer.setInterval(1000);
}

Worker::~Worker()
{
    qInfo() << this << "Deconstructed on " << QThread::currentThread();
}

void Worker::start()
{
    qInfo() << this << "Started on " << QThread::currentThread();
    timer.start();
    loop.exec(); // Processing stays here

    qInfo() << this << "Loop finished on " << QThread::currentThread();

    //this->deleteLater(); //may hold on to this for a while!
    delete this;
}

void Worker::stop()
{
    qInfo() << this << "Stopping on " << QThread::currentThread();
    timer.stop();
    loop.quit();
    qInfo() << this << "Stopped on " << QThread::currentThread();
}

void Worker::timeout()
{
    qInfo() << this << "Timeout on " << QThread::currentThread();
}
