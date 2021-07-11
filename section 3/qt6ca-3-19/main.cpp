/*

  What
  Waiting for values in the future

  Why
  Threading is not syncronous

  How
  QFutureWatcher - signals and slots based approach

*/

#include <QCoreApplication>
#include <QDebug>
#include <QFuture>
#include <QFutureWatcher>
#include <QList>
#include <QtConcurrent>
#include "test.h"

void multiply(int &value)
{
    qInfo() << "Called: " << value;
    value = value * 10;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    for(int i = 0; i < 100; i++)
    {
        list.append(i);
    }

    QFutureWatcher<void> watcher;
    Test test;
    QObject::connect(&watcher, &QFutureWatcher<void>::finished,&test,&Test::finished); //Auto connect "should" work

    QFuture<void> future = QtConcurrent::map(list,&multiply);
    watcher.setFuture(future);

    qInfo() << "Back in main!";

     watcher.waitForFinished(); //Blocking

     qInfo() << "Done!";
     qInfo() << list;

    return a.exec();
}
