/*

  What
  Basic testing

  Why
  Lets look deeper at testing

  How
  Example code

 */

#include <QCoreApplication>
#include <QTest>
#include "dog.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Dog dog;
    QTest::qExec(&dog);

    return a.exec();
}
