/*
    What
    Signals and slots across threads

    Why
    Some minor complications

    How
    Qt Signal Types

*/

#include <QCoreApplication>
#include <QThreadPool>
#include "widget.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Widget* producer = new Widget();
    Widget* consumer = new Widget();

    producer->setObjectName("Producer");
    consumer->setObjectName("Consumer");
    producer->setIsSender(true);
    producer->setAutoDelete(true);
    consumer->setAutoDelete(true);

    QObject::connect(producer,&Widget::started,consumer,&Widget::workStarted,Qt::QueuedConnection);
    QObject::connect(producer,&Widget::update,consumer,&Widget::workReady,Qt::QueuedConnection);
    QObject::connect(producer,&Widget::finished,consumer,&Widget::workFinished,Qt::QueuedConnection);

    QThreadPool::globalInstance()->start(producer);
    QThreadPool::globalInstance()->start(consumer);

    return a.exec();
}
