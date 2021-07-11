/*

  What
  UDP

  Why
  We want to send and recive and not care about a connection

  How
  QUdpSocket

*/

#include <QCoreApplication>
#include "worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Worker worker;
    worker.start();

    return a.exec();
}
