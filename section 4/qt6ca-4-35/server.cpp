#include "server.h"

Server::Server(QObject *parent) : QTcpServer(parent)
{

}

void Server::setCert(QString value)
{
    certPath = value;
}

void Server::setKey(QString value)
{
    keyPath = value;
}

void Server::disconnected()
{
    QSslSocket* socket = qobject_cast<QSslSocket*>(sender());
    qInfo() << "Disconnected" << socket;
    socket->deleteLater();
}

void Server::readyRead()
{
    QSslSocket* socket = qobject_cast<QSslSocket*>(sender());
    qInfo() << "ReadyRead" << socket;

    qInfo() << socket->readAll();

    QByteArray data("Hello World!\r\n");
    QByteArray response;
    response.append("HTTP/1.1 200 OK\r\n");
    response.append("Content-Type: text/plain\r\n");
    //Qt5
    //response.append("Content-Length: " + QString::number(data.length()) + "\r\n");
    response.append("Content-Length: " + QString::number(data.length()).toUtf8() + "\r\n");
    response.append("Connection: close\r\n");
    response.append("\r\n");
    response.append(data);

    socket->write(response);
    socket->waitForBytesWritten();

    socket->close();
    socket->deleteLater();

}

void Server::encrypted()
{
    QSslSocket* socket = qobject_cast<QSslSocket*>(sender());
    qInfo() << "Encrypted" << socket;
}

void Server::encryptedBytesWritten(qint64 written)
{
    QSslSocket* socket = qobject_cast<QSslSocket*>(sender());
    qInfo() << "encryptedBytesWritten" << socket;
}

void Server::modeChanged(QSslSocket::SslMode mode)
{
    QSslSocket* socket = qobject_cast<QSslSocket*>(sender());
    qInfo() << "modeChanged" << socket << mode;
}

void Server::peerVerifyError(const QSslError &error)
{
    QSslSocket* socket = qobject_cast<QSslSocket*>(sender());
    qInfo() << "peerVerifyError" << socket;
}

void Server::sslErrors(const QList<QSslError> &errors)
{
    QSslSocket* socket = qobject_cast<QSslSocket*>(sender());
    qInfo() << "sslErrors" << socket;
    socket->ignoreSslErrors(errors);
}

void Server::socketError(QAbstractSocket::SocketError err)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketError>();
    QSslSocket* socket = qobject_cast<QSslSocket*>(sender());
    qInfo() << "socketError: " << socket << metaEnum.valueToKey(err);
}

void Server::incomingConnection(qintptr handle)
{
    qInfo() << "incomming connection " << handle;
    QSslSocket* socket = new QSslSocket(this);

    connect(socket,&QSslSocket::disconnected,this,&Server::disconnected);
    connect(socket,&QSslSocket::readyRead,this,&Server::readyRead);

    connect(socket,&QSslSocket::encrypted,this,&Server::encrypted);
    connect(socket,&QSslSocket::encryptedBytesWritten,this,&Server::encryptedBytesWritten);
    connect(socket,&QSslSocket::modeChanged,this,&Server::modeChanged);
    connect(socket,&QSslSocket::peerVerifyError,this,&Server::peerVerifyError);
    connect(socket,QOverload<const QList<QSslError> &>::of(&QSslSocket::sslErrors),this,&Server::sslErrors);

    //Qt5
    //connect(socket,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this, &Server::socketError);
    connect(socket,&QSslSocket::errorOccurred,this,&Server::socketError);

    qInfo() << "Connected" << socket;
    socket->setSocketDescriptor(handle);
    socket->setLocalCertificate(certPath,QSsl::Pem);
    socket->setPrivateKey(keyPath, QSsl::Rsa, QSsl::Pem);
    socket->setPeerVerifyMode(QSslSocket::VerifyNone);

    //Qt5
    //socket->setProtocol(QSsl::TlsV1SslV3);

    QList<QSslCertificate> localChain;
    QSslCertificate cert;
    cert.fromPath(certPath);
    localChain.append(cert);
    socket->setLocalCertificateChain(localChain);

    socket->setProtocol(QSsl::SslProtocol::TlsV1_2);
    socket->startServerEncryption();


}
