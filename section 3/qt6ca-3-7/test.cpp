#include "test.h"

Test::Test(QObject *parent) : QThread(parent)
{

}


void Test::run()
{
    //Notice after 3 seconds nothing happens!!!
    m_timer.singleShot(3000,this,&Test::test);
    test();
}

void Test::test()
{
    //Notice this gets run last!
    qInfo() << "TESTING" << currentThread();

    terminate();

    //Bad things happen from here...
}
