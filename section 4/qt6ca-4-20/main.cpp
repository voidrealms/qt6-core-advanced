/*

  What
  Network Proxy

  Why
  We want to connect to a host via a proxy
  Could be a company policy
  Maybe we want to mask our identity

  How
  QNetworkProxy

  https://free-proxy-list.net/

*/


#include <QCoreApplication>
#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Client client;
    client.connectToHost("www.httpbin.org", 80);

    return a.exec();
}
