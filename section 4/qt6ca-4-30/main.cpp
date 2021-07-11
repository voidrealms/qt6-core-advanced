/*

  What
  Create a TCP Server

  Why
  We want to make a custom server

  How
  QTcpServer

 */

#include <QCoreApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;
    server.start();


    return a.exec();
}
