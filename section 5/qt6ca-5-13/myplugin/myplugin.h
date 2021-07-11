#ifndef MYPLUGIN_H
#define MYPLUGIN_H

#include <QObject>
#include <QtPlugin>
#include <QDebug>
#include <QString>
#include "plugin.h"

class MyPlugin: public QObject, public Plugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.voidrealms.plugin")
    Q_INTERFACES(Plugin)

public:
    explicit MyPlugin(QObject* parent = nullptr);
    ~MyPlugin();

signals:

public slots:

    // Plugin interface
public:
    void test(QString name) Q_DECL_OVERRIDE; // override
};

#endif // MYPLUGIN_H
