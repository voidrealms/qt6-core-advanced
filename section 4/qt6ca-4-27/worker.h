#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QDateTime>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QThread>
#include <QEventLoop>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    ~Worker();

signals:

public slots:
    void start();
    void stop();
    void timeout();
    void readyRead();
    void broadcast();

private:
    QUdpSocket* socket;
    QTimer* timer;
    QEventLoop *loop;
    quint16 port = 2020; //Note < 1024 those admin ports / special services. HTTP, FTP, POP3, SMTP
    int counter;
};

#endif // WORKER_H
