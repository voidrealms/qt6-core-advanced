/*

  What
  UDP Chat example

  Why
  We want to see how it works

  How
  See the code

*/

#include <QCoreApplication>
#include <QFuture>
#include <QtConcurrent>
#include "commandline.h"
#include "chat.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CommandLine cli(&a,stdin);

    QFuture<void> future = QtConcurrent::run(&CommandLine::monitor,&cli);

    Chat chat;
    QObject::connect(&cli,&CommandLine::command,&chat,&Chat::command,Qt::QueuedConnection);

    qInfo() << "Enter your name to begin:";

    return a.exec();
}
