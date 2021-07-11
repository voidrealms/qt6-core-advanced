#ifndef DOG_H
#define DOG_H

#include <QObject>
#include <QDebug>

class Dog : public QObject
{
    Q_OBJECT
public:
    explicit Dog(QObject *parent = nullptr);

signals:

public slots:

private slots:
    //Called before the first test
    void initTestCase();

    //Called before each test
    void init();

    //Called after each test
    void cleanup();

    //Called after the last test
    void cleanupTestCase();

    //Our custom slot to be tested
    void bark();

    //Another custom slot to test
    void rollover();
};

#endif // DOG_H
