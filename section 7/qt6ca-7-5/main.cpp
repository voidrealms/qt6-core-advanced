/*

  What
  Testing for failure

  Why
  This is the reason for testing

  How
  QFAIL QVERIFY QCOMPARE QWARN

*/


#include <QCoreApplication>
#include <QTest>
#include "widget.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Widget widget;
    widget.setAge(46);
    QTest::qExec(&widget);

    return a.exec();
}
