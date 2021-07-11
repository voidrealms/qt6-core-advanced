#include "manager.h"

Manager::Manager(QObject *parent) : QObject(parent)
{

}

Manager::~Manager()
{
    quit();
}

void Manager::process()
{
    QFuture<void> value = QtConcurrent::run(Manager::createWorker,this);
}

void Manager::quit()
{
    qInfo() << "Stopping Manager";
    emit stop();
}

void Manager::createWorker(Manager *manager)
{
    qInfo() << "Creating Worker";
    Worker* worker = new Worker();
    connect(manager,&Manager::start, worker, &Worker::start); // Qt::QueuedConnection
    connect(manager,&Manager::stop, worker, &Worker::stop); // Qt::QueuedConnection
    worker->start();
}
