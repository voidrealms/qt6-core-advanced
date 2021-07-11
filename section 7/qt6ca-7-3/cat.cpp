#include "cat.h"

Cat::Cat(QObject *parent) : QObject(parent)
{
    qInfo() << Q_FUNC_INFO;
}

void Cat::public_test()
{
    qInfo() << Q_FUNC_INFO;

}

void Cat::test()
{
    qInfo() << Q_FUNC_INFO;
}

void Cat::play()
{
    qInfo() << Q_FUNC_INFO;
}

void Cat::meow()
{
    qInfo() << Q_FUNC_INFO;
}

void Cat::sleep()
{
    qInfo() << Q_FUNC_INFO;
}

void Cat::speak(QString value)
{
    Q_UNUSED(value);
    qInfo() << Q_FUNC_INFO;
}

void Cat::private_test()
{
    qInfo() << Q_FUNC_INFO;
}
