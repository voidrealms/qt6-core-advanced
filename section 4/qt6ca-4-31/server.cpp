#include "server.h"

Server::Server(QObject *parent) : QTcpServer(parent)
{
    pool.setMaxThreadCount(200);
    qInfo() << "Threads: " << pool.maxThreadCount();
}

void Server::start(quint16 port)
{
    qInfo() << this << " start " << QThread::currentThread();
    if(this->listen(QHostAddress::Any, port))
    {
        qInfo() << "Server started on " << port;
    }
    else
    {
        qCritical() << this->errorString();
    }
}

void Server::quit()
{
    this->close();
    qInfo() << "Server Stopped!";
}

void Server::incomingConnection(qintptr handle)
{
    //Not version friendly!!!
    qInfo() << "Incomming Connection " << handle << " on " << QThread::currentThread();
    Client* client = new Client(nullptr, handle);
    client->setAutoDelete(true);
    pool.start(client);

}
