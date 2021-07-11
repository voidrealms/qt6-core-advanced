#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{
    m_host = "";
    m_port = 0;
}

Client::~Client()
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();
    qInfo() << "Deconstructor";
}

void Client::connectToHost(QString host, quint16 port)
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();
    if(socket->isOpen()) disconnect();
    qInfo() << "Connecting to: " << host << " on port " << port;

    socket->connectToHost(host,port);
}

void Client::disconnect()
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();
    socket->close();
}

void Client::run()
{
    //Our code starts running on a thread here...
    qInfo() << Q_FUNC_INFO << QThread::currentThread();

    socket = new QTcpSocket(this);
    connect(socket,&QTcpSocket::connected,this,&Client::connected);
    connect(socket,&QTcpSocket::disconnected,this,&Client::disconnected);

    connect(socket,&QTcpSocket::stateChanged,this,&Client::stateChanged);
    connect(socket,&QTcpSocket::readyRead,this,&Client::readyRead);
    //Qt 5
    //connect(&socket,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,&Client::error); //Explain
    connect(socket,&QTcpSocket::errorOccurred,this,&Client::error);

    connectToHost(m_host,m_port);

    //Design choices here!
    socket->waitForDisconnected(); //BLOCK
    qInfo() << "Complete!";
    deleteLater();


}//Keep the thread alive

void Client::connected()
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();
    qInfo() << "Connected!";

    qInfo() << "Sending";
    socket->write("HELLO\r\n");
}

void Client::disconnected()
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();
    qInfo() << "Disconnected";
}

void Client::error(QAbstractSocket::SocketError socketError)
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();
    qInfo() << "Error:" << socketError << " " << socket->errorString();
}

void Client::stateChanged(QAbstractSocket::SocketState socketState)
{
    //qInfo() << Q_FUNC_INFO << QThread::currentThread();
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketState>();
    qInfo() << "State: " << metaEnum.valueToKey(socketState);
}

void Client::readyRead()
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();
    qInfo() << "Data from: " << sender() << " bytes: " << socket->bytesAvailable() ;
    qInfo() << "Data: " << socket->readAll();
}

quint16 Client::port() const
{
    return m_port;
}

void Client::setPort(quint16 newPort)
{
    m_port = newPort;
}

const QString &Client::host() const
{
    return m_host;
}

void Client::setHost(const QString &newHost)
{
    m_host = newHost;
}
