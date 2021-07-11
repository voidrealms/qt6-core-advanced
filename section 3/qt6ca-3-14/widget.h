#ifndef WIDGET_H
#define WIDGET_H

#include <QObject>
#include <QRunnable>
#include <QThread>
#include <QDebug>

class Widget : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Widget(QObject *parent = nullptr);

signals:
    void started();
    void finished();
    void update(int i);

public slots:
    void workStarted();
    void workFinished();
    void workReady(int i);

public:
    void run();
    bool isSender() const;
    void setIsSender(bool newIsSender);

private:
    bool m_isSender;
    bool m_isActive;
};

#endif // WIDGET_H
