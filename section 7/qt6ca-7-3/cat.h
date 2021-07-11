#ifndef CAT_H
#define CAT_H

#include <QObject>
#include <QDebug>


class Cat : public QObject
{
    Q_OBJECT
public:
    explicit Cat(QObject *parent = nullptr);
    void public_test(); //not called

signals:

public slots:

    void test(); //not called


private slots:
    void play();
    void meow();
    void sleep();
    void speak(QString value); //no param

private:
    void private_test(); //not called
};

#endif // CAT_H
