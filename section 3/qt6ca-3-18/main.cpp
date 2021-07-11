/*

  What
  Qt Concurrent issues

  Why
  We live in the real world
  Its great, but we lose a lot of control

  How
  Example code: we have to use Futures to get values back

*/

#include <QCoreApplication>
#include <QtConcurrent>
#include <QThread>
#include <QFuture>

void test(QString name, int max)
{
    for (int i = 0;i < max;i++)
    {
        qInfo() << name << i << QThread::currentThread();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString name = "name";

    QFuture<void> future = QtConcurrent::run(test,name,5);
    qInfo() << "Do stuff here";

    //Wait for finished
    future.waitForFinished(); //Block
    qInfo() << "Done";

    return a.exec();
}
