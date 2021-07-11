#include "cats.h"


Cats::Cats(QObject *parent)
{
    Q_UNUSED(parent);
    qInfo() << "Plugin Constructed";
}

Cats::~Cats()
{
    qInfo() << "Plugin Deconstructed";
}


void Cats::test(QString name)
{
    qInfo() << "Cat says: " << name;
}
