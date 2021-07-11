/*

  What
  Network interfaces and addresses

  Why
  We can have more than one!

  How
  QHostAddress

 */

#include <QCoreApplication>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QAbstractSocket>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QHostAddress> list = QNetworkInterface::allAddresses();

    for(int  i = 0; i < list.count(); i++)
    {
        QHostAddress address = list.at(i);
        qInfo() << address.toString();

        //Never goes on the network
        qInfo() << "\t Loopback:" << address.isLoopback();

        //Send to many
        qInfo() << "\t Multicast:" << address.isMulticast();

        switch (address.protocol())
        {
        case QAbstractSocket::UnknownNetworkLayerProtocol:
            qInfo() << "\tProtocol: Unknown";
            break;
        case QAbstractSocket::AnyIPProtocol:
            qInfo() << "\tProtocol: Any";
            break;
        case QAbstractSocket::IPv4Protocol:
            qInfo() << "\tProtocol: IP4";
            break;
        case QAbstractSocket::IPv6Protocol:
            qInfo() << "\tProtocol: IP6";
            break;
        }
    }

    return a.exec();
}
