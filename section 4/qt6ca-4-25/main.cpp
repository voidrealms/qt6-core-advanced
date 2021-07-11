/*

  What
  Asynchronous UDP

  Why
  This is how we normally work with it

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
    Worker worker;
    worker.start();

    return a.exec();
}
