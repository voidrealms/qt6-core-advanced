/*

  What
  Work with FTP servers

  Why
  We want to upload and download using FTP

  How
  QNetworkAccessManager FTP

  NOTE - they took FTP out of Qt 6 and will eventually move it to a different lib
  You will get Error:  QNetworkReply::ProtocolUnknownError
  Even using Core5Compat wont fix this, you will need to wait until they release the module, or make your own
  (You can always use Qt5)

  https://www.qt.io/blog/qt-network-in-qt-6
  https://doc-snapshots.qt.io/qt6-dev/qtscxml-ftpclient-example.html


 */

#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>
#include "worker.h"
#include <QNetworkAccessManager>

//QNetworkAccessManager - FTP Example

void upload(Worker* worker, QString path)
{
    QString location = "ftp://speedtest.tele2.net/upload/VoidRealms-" + QString::number(QDateTime::currentSecsSinceEpoch()) + ".bin";
    worker->upload(location,path);

}

void download(Worker* worker, QString path)
{
    QString location = "ftp://speedtest.tele2.net/512KB.zip";
    worker->download(location,path);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QNetworkAccessManager manager;
    qInfo() << manager.supportedSchemes(); //Shows what is supported in Qt 6

    Worker worker;
    //upload(&worker,"test.txt");
    //download(&worker,"test.zip");

    return a.exec();
}
