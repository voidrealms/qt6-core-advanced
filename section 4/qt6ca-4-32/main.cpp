/*

  What
  High performance multi-threaded TCP server

  Why
  Lets see how to make it fast

  How
  Code example
  Test with Siege
  https://www.joedog.org/siege-home/

  siege -c 1 127.0.0.1:2020
  siege -c 10 127.0.0.1:2020
  siege -c 100 127.0.0.1:2020

*/

#include <QCoreApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;
    server.start(2020);

    return a.exec();
}
