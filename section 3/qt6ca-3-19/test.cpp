#include "test.h"

Test::Test(QObject *parent) : QObject(parent)
{

}

void Test::finished()
{
    //When Qt Concurrent is done
    qInfo() << this << "Processing...";
}
