#include "widget.h"

Widget::Widget(QObject *parent) : QObject(parent)
{
    m_isSender = false;
}

void Widget::workStarted()
{
    qInfo() << this <<  "Started" << sender();
}

void Widget::workFinished()
{
    qInfo() << this <<  "Finished" << sender();
    m_isActive = false;
}

void Widget::workReady(int i)
{
    qInfo() << this << "Work" << i << sender();
}

void Widget::run()
{
    if(m_isSender)
    {
        qInfo() << this << "Starting work...";
        emit started();

        for(int i = 0; i < 10; i++)
        {
            qInfo() << this << "Update...";
            emit update(i);
            QThread::currentThread()->msleep(500);
        }
        qInfo() << this << "Finished...";
        emit finished();
    }
    else
    {
        qInfo() << this << "Waiting for signals...";
        m_isActive = true;
        while(m_isActive)
        {
            QThread::currentThread()->msleep(100);
        }
    }

    qInfo() << this << "Done";
}

bool Widget::isSender() const
{
    return m_isSender;
}

void Widget::setIsSender(bool newIsSender)
{
    m_isSender = newIsSender;
}
