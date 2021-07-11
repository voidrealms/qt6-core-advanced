#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include <QDebug>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

signals:

public slots:
    void run();

private slots:
    void timeout();

private:
    QTimer m_timer;

};

#endif // TEST_H
