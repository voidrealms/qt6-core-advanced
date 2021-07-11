#include "worker.h"

Worker::Worker(QObject *parent) : QObject(parent)
{
    connect(&manager,&QNetworkAccessManager::finished,this,&Worker::finished);
}

void Worker::upload(QString location, QString path)
{
    qInfo() << "Uploading: " << path;

    file.setFileName(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        qInfo() << file.errorString();
        return;
    }

    QUrl url(location);
    //url.setPassword("anonymous");
    //url.setUserName("anonymous");
    //url.setPort(21);

    QNetworkRequest request = QNetworkRequest(url);
    QNetworkReply* reply = manager.put(request,&file);
    wire(reply);

}

void Worker::download(QString location, QString path)
{
    qInfo() << "Downloading: " << path;

    file.setFileName(path);
    if(!file.open(QIODevice::WriteOnly))
    {
        qInfo() << file.errorString();
        return;
    }

    QUrl url(location);
    //url.setPassword("anonymous");
    //url.setUserName("anonymous");
    //url.setPort(21);

    QNetworkRequest request = QNetworkRequest(url);

    QNetworkReply* reply = manager.get(request);
    wire(reply);
}

void Worker::readyRead()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    if(reply)
    {
        QByteArray data = reply->readAll();
        file.write(data);
    }
}

void Worker::finished(QNetworkReply *reply)
{
    qInfo() << "Finished";
    file.close();
    reply->close();
}

void Worker::uploadProgress(qint64 bytesSent, qint64 bytesTotal)
{
    if(bytesTotal <= 0) return;
    qInfo() << "Uploading: " << bytesSent << " of " << bytesTotal;

}

void Worker::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    if(bytesTotal <= 0) return;
    qInfo() << "Downloading: " << bytesReceived << " of " << bytesTotal;
}

void Worker::error(QNetworkReply::NetworkError code)
{
    qInfo() << "Error: " << code;
}

void Worker::wire(QNetworkReply *reply)
{
    connect(reply,&QNetworkReply::readyRead,this,&Worker::readyRead);
    connect(reply,&QNetworkReply::uploadProgress,this,&Worker::uploadProgress);
    connect(reply,&QNetworkReply::downloadProgress,this,&Worker::downloadProgress);
    //Qt5
    //connect(reply,QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error),this,&Worker::error);
    connect(reply,&QNetworkReply::errorOccurred,this,&Worker::error);
}
