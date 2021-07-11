/*

  What
  Assignment

  Why
  Practice what you learned

  How
  Counting files in folders

*/

#include <QCoreApplication>
#include <QDebug>
#include <QFuture>
#include <QtConcurrent>
#include <QDirIterator>

void count(QString path)
{
    QDirIterator it(path, QDir::Files,QDirIterator::Subdirectories);
    int value = 0;
    while(it.hasNext())
    {
        qInfo() <<it.next();
        value++;
    }
    qInfo() << "Found" << value << " files";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir root = QDir::current();
    root.cdUp();

    QFuture<void> future = QtConcurrent::run(&count,root.path());
    qInfo() << "Counting file...";

    //Do other things...

    future.waitForFinished();

    qInfo() << "Done";


    return a.exec();
}
