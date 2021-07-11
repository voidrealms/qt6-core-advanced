#include "myplugin.h"


MyPlugin::MyPlugin(QObject *parent)
{
    Q_UNUSED(parent);
    qInfo() << "Plugin Constructed";
}

MyPlugin::~MyPlugin()
{
    qInfo() << "Plugin Deconstructed";
}


void MyPlugin::test(QString name)
{
    qInfo() << "Test from plugin: " << name;
}
