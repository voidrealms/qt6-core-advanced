/*

  What
  Thread Pools

  Why
  We want multiple resuable threads

  How
  QTreadPool and QRunnable

 */


#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include <QThreadPool>
#include "counter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QThread::currentThread()->setObjectName("Main");

    QThreadPool* pool = QThreadPool::globalInstance();
    qInfo() << pool->maxThreadCount() << "Threads";

    for(int i = 0; i < 100; i++)
    {
        Counter* c = new Counter();
        c->setAutoDelete(true);
        pool->start(c);
    }

    return a.exec();
}
