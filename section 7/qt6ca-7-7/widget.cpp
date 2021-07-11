#include "widget.h"

Widget::Widget(QObject *parent) : QObject(parent)
{

}

void Widget::testFor()
{
    QVector<int> list;
    list.fill(0,100);

    //Called multiple times!
    QBENCHMARK
    {
        for (int i = 0; i < list.size();i++)
        {
            //Do Stuff
        }
    }
}

void Widget::testForEach()
{
    QVector<int> list;
    list.fill(0,100);

    //Called multiple times!
    QBENCHMARK
    {
        foreach(int value, list)
        {
            //Do Stuff
        }
    }
}

void Widget::testString()
{
    QString him = "Bryan";
    QString her = "Tammy";

    QBENCHMARK
    {
        int ret = him.compare(her);
    }
}

void Widget::testComp()
{
    QString him = "Bryan";
    QString her = "Tammy";

    QBENCHMARK
    {
        QCOMPARE(him, her);
    }
}
