/*

  What
  Future watcher signals and slots

  Why
  We want to use Qt signals and slots

  How
  QFutureWatcher Slots

*/


#include <QCoreApplication>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test test;
    test.process();


    return a.exec();
}
