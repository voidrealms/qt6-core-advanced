/*

  What
  Make HTTP Calls

  Why
  We want to work with web servers

  How
  QNetworkAccessManager HTTP

 */

#include <QCoreApplication>
#include "worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Worker worker;
    worker.get("https://postman-echo.com/get?foo1=bar1&foo2=bar2");

    QByteArray data;
    data.append("param1=hello");
    data.append("&");
    data.append("param2=foo");

    worker.post("https://postman-echo.com/post",data);

    return a.exec();
}
