/*

  What
  Returning values

  Why
  We want to get the result

  How
  Future results

*/

#include <QCoreApplication>
#include <QDebug>
#include <QFuture>
#include <QFutureWatcher>
#include <QList>
#include <QtConcurrent>

int multiply(const int &value)
{
    qInfo() << "Called: " << value;
    int num = value * 10;
    return num;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    for (int i = 0;i < 100; i++)
    {
        list.append(i);
    }

    QFutureWatcher<int> watcher;
    QFuture<int> future = QtConcurrent::mapped(list,&multiply);
    watcher.setFuture(future);
    //Set signals and slots here

    qInfo() << "Back in main!";

    //Do other things with the watcher if needed
    watcher.waitForFinished();

    qInfo() << "Done!";
    qInfo() << future.results();


    return a.exec();
}
