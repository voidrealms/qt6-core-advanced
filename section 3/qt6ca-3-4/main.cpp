/*

  What
  Synchronous example

  Why
  Understand whats happening when we run code

  How
  Synchronous code

 */

#include <QCoreApplication>
#include <QThread>

void test()
{
    qInfo() << "Testing" << QThread::currentThread();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");
    qInfo() << "Starting" << QThread::currentThread();
    test();
    qInfo() << "Finished" << QThread::currentThread();

    return a.exec();
}
