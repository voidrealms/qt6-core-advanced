#ifndef WIDGET_H
#define WIDGET_H

#include <QObject>
#include <QDebug>
#include <QTest>

class Widget : public QObject
{
    Q_OBJECT
public:
    explicit Widget(QObject *parent = nullptr);

signals:

public slots:

private slots:
    void testFor();
    void testForEach();
    void testString();
    void testComp();

};

#endif // WIDGET_H
