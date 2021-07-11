/*

  What
  SSL Client

  Why
  We want an encrypted TCP connection

  How
  QSsLSocket

 */


#include <QCoreApplication>
#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Client client;
    //client.connectToHost("www.httpbin.org", 80); //Not encrypted
    client.connectToHost("httpbin.org", 443); //SSL - OpenSsl
    return a.exec();
}
