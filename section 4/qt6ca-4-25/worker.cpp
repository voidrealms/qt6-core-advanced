#include "worker.h"

Worker::Worker(QObject *parent) : QObject(parent)
{
    connect(&timer,&QTimer::timeout,this,&Worker::timeout);
    connect(&socket,&QUdpSocket::readyRead,this,&Worker::readyRead);
    timer.setInterval(1000);
}

void Worker::start()
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();
    if(!socket.bind(port))
    {
        qInfo() << socket.errorString();
        return;
    }

    qInfo() << "Started UDP on " << socket.localAddress() << ":" << socket.localPort();

    broadcast();
}

void Worker::stop()
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();
    timer.stop();
    socket.close();
    qInfo() << "Stopped";
}

void Worker::timeout()
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();
    QString date = QDateTime::currentDateTime().toString();
    QByteArray data = date.toLatin1();

    QNetworkDatagram datagram(data,QHostAddress::Broadcast,port);
    qInfo() << "Send: " << data;
    socket.writeDatagram(datagram);
}

void Worker::readyRead()
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();
    while (socket.hasPendingDatagrams())
    {
        QNetworkDatagram datagram = socket.receiveDatagram();
        qInfo() << "Read: " << datagram.data() << " from " << datagram.senderAddress() << ":" << datagram.senderPort();
    }
}

void Worker::broadcast()
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();
    qInfo() << "Broadcasting...";
    timer.start();
}
