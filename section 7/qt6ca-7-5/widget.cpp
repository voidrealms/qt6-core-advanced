#include "widget.h"

Widget::Widget(QObject *parent) : QObject(parent)
{
    age = 0;
}

void Widget::setAge(int value)
{
    age = value;
}

void Widget::testFail()
{
    QFAIL("NO REASON JUST FAIL!!!");
}

void Widget::testAge()
{
    if(!age) QFAIL("Age is not set!");
}

void Widget::testWidget()
{

    int value = 45;

    //Make sure the age is valid--------------
    QVERIFY(age > 0 && age < 100);

    //Issue warnings
    if(age > 40) QWARN("Age is over 40!");
    if(age < 21) QFAIL("Must be an adult!");

    //Make sure they are the same---------------------
    QCOMPARE(age, value);


}
