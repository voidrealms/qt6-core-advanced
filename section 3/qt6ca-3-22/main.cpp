/*

  What
  Interate over Future values

  Why
  We want to sync values

  How
  QFutureIterator

 */

#include <QCoreApplication>
#include <QtConcurrent>
#include <QFuture>
#include <QList>
#include <QFutureIterator>

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
    for (int i = 0;i < 100;i++)
    {
        list.append(i);
    }

    //Do stuff async   -----------------------------------
    QFutureWatcher<int> watcher;
    QFuture<int> future = QtConcurrent::mapped(list,&multiply);
    watcher.setFuture(future);

    //Blocking style  ----------------------------------------
    watcher.waitForFinished();


    //Java style   ------------------------------------------
    QFutureIterator<int> iter(future);
    while(iter.hasNext())
    {
        qInfo() << "Java: " << iter.next();
    }

    //Index style (normal c++)   ----------------------------
    for(int i = 0; i < future.results().length(); i++)
    {
        qInfo() << "Index: " << future.resultAt(i);
    }

    //Qt style---------------------------------
    foreach(int i, future.results())
    {
        qInfo() << "Qt: " << i;
    }

    //STD --------------------
    QList<int> values = future.results();
    for(auto i = values.begin(); i < values.end(); i++)
    {
        qInfo() << "STD: " << *i;
    }

    qInfo() << "Done";

    return a.exec();
}
