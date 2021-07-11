/*

  What
  Asynchronous example

  Why
  Understand whats happening when we run code

  How
  Asynchronous code

 */

#include <QCoreApplication>
#include <QThread>
#include <QTimer>

void test()
{
    qInfo() << "Testing" << QThread::currentThread();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");

    qInfo() << "Starting" << QThread::currentThread();
    QTimer timer;
    timer.singleShot(3000,&test);
    qInfo() << "Finished" << QThread::currentThread();

    return a.exec();
}
