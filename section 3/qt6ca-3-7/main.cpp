/*

  What
  Inheriting QThread

  Why
  This is BAD, do not do this!
  Folks familiar with java will try this
  Its bad because you can easily break the way threading works
  This is super confusing as Qt documentation even uses this!

  How
  Threaded code

 */


#include <QCoreApplication>
#include <QThread>
#include "test.h"
#include "worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QThread::currentThread()->setObjectName("Main Thread");

    Test thread;
    thread.setObjectName("Thread 1");

    Worker worker;
    worker.moveToThread(&thread);
    QObject::connect(&thread,&QThread::started,&worker,&Worker::work);
    thread.start();

    return a.exec();
}
