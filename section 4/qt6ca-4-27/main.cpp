/*

  What
  Threaded UDP

  Why
  We want to use threading and async

  How
  Remember slots block!

 */

#include <QCoreApplication>
#include <QThread>
#include "worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");

    QThread thread;
    thread.setObjectName("Worker Thread");
    Worker* worker = new Worker();
    worker->moveToThread(&thread);
    QObject::connect(&thread,&QThread::started,worker,&Worker::start);
    thread.start();

    return a.exec();
}
