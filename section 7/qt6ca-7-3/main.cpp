/*

  What
  Lets test

  Why
  To see how it works

  How
  Example

 */

#include <QCoreApplication>
#include <QTest>
#include "cat.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Cat cat;
#ifdef QT_DEBUG
    QTest::qExec(&cat);
#endif
    return a.exec();
}
