#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>
#include <QThread>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

signals:

public slots:
    void work();

};

#endif // WORKER_H
