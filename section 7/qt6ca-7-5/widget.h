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

    void setAge(int value);

signals:

public slots:

private slots:
    void testFail();
    void testAge();
    void testWidget();

private:
    int age;
};

#endif // WIDGET_H
