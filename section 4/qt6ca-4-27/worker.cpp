#include "worker.h"

Worker::Worker(QObject *parent) : QObject(parent)
{

}

Worker::~Worker()
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();
    qInfo() << "Deconstructed";
}

void Worker::start()
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();

    timer = new QTimer(this);
    socket = new QUdpSocket(this);
    loop = new QEventLoop(this);
    counter = 0;

    connect(timer,&QTimer::timeout,this,&Worker::timeout);
    connect(socket,&QUdpSocket::readyRead,this,&Worker::readyRead);
    timer->setInterval(1000);

    if(!socket->bind(port))
    {
        qInfo() << socket->errorString();
        return;
    }

    qInfo() << "Started UDP on " << socket->localAddress() << ":" << socket->localPort();

    broadcast();
    loop->exec(); //BLOCK
}

void Worker::stop()
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();
    timer->stop();
    socket->close();

    if(loop)
    {
        qInfo() << "Stopping event loop";
        loop->quit();
        delete loop;
    }

    qInfo() << "Stopped";
    deleteLater();
}

void Worker::timeout()
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();
    QString date = QDateTime::currentDateTime().toString();
    QByteArray data = date.toLatin1();

    QNetworkDatagram datagram(data,QHostAddress::Broadcast,port);
    qInfo() << "Send: " << data;
    socket->writeDatagram(datagram);

    counter++;
    if(counter >= 3) stop();

}

void Worker::readyRead()
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();
    while (socket->hasPendingDatagrams())
    {
        QNetworkDatagram datagram = socket->receiveDatagram();
        qInfo() << "Read: " << datagram.data() << " from " << datagram.senderAddress() << ":" << datagram.senderPort();
    }
}

void Worker::broadcast()
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();
    qInfo() << "Broadcasting...";
    timer->start();
}
