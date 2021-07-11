/*

  What
  Synchronous UDP

  Why
  We want UDP but we also want to block

  How
  Example code

 */

#include <QCoreApplication>
#include <QDebug>
#include <QUdpSocket>
#include <QDateTime>
#include <QNetworkDatagram>

bool bind(QUdpSocket* socket, quint16 port)
{
    if(socket->bind(port,QUdpSocket::ShareAddress)) return true;

    qInfo() << socket->errorString();
    return false;
}

void send(QUdpSocket* socket, quint16 port)
{
    qInfo() << "Sending...";
    QString date = QDateTime::currentDateTime().toString();
    QByteArray data = date.toLatin1();

    QNetworkDatagram datagram(data,QHostAddress::Broadcast,port);
    if(socket->writeDatagram(datagram) <= 0)
    {
        qInfo() << socket->errorString();
    }
}

void read(QUdpSocket* socket)
{
    qInfo() << "Reading...";
    socket->waitForReadyRead(60000);
    while(socket->hasPendingDatagrams())
    {
        QNetworkDatagram datagram = socket->receiveDatagram();
        qInfo() << datagram.data();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QUdpSocket broadcaster;
    QUdpSocket client;
    quint16 port = 4569;

    qInfo() << "Binding...";
    if(bind(&broadcaster,port) && bind(&client,port))
    {
        send(&broadcaster,port);
        read(&client);
    }
    else
    {
        qInfo() << "Could not bind";
    }

    return a.exec();
}
