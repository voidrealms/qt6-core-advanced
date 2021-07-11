#include "test.h"

Test::Test(QObject *parent) : QObject(parent)
{

}

void Test::run()
{
    qInfo() << "Running" << QThread::currentThread();
    m_timer.singleShot(3000,this,&Test::timeout);
    qInfo() << "Finished" << QThread::currentThread();
}

void Test::timeout()
{
    qInfo() << "Timeout" << QThread::currentThread();
}
