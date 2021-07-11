#include "widget.h"

Widget::Widget(QObject *parent) : QObject(parent)
{

}

void Widget::testAge_data()
{
    qInfo() << "Generating data...";

    QTest::addColumn<QString>("name");
    QTest::addColumn<int>("age");

    QTest::addRow("Invalid") << "Bob" << 190;
    QTest::addRow("Old") << "Bryan" << 44;
    QTest::addRow("Young") << "Heather" << 25;
    QTest::addRow("Under age") << "Rango" << 14;
    QTest::addRow("Retired") << "Grandma" << 90;

    qInfo() << "Data generated!";
}

void Widget::testAge()
{
    QFETCH(QString,name);
    QFETCH(int, age);

    qInfo() << "Testing age " << name << " is " << age;

    if(age < 1 || age > 100) QFAIL("Invalid Age!");
    if(age < 21) QFAIL("Must be an adult!");
    if(age > 40) QWARN("Getting Old!");
    if(age > 65) qInfo() << "This person is retired";
}
