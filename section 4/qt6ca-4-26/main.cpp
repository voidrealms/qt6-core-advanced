/*

  What
  Threaded TCP

  Why
  We want to use both Threaded and Async code

  How
  QThread and QTcpSocket

*/

#include <QCoreApplication>
#include <QThread>
#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");

    QThread thread;
    thread.setObjectName("Client Thread");

    Client* client = new Client();
    client->moveToThread(&thread);
    QObject::connect(&thread, &QThread::started,client,&Client::run);
    client->setHost("voidrealms.com");
    client->setPort(80);

    thread.start();




    return a.exec();
}
