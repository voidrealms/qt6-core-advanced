/*
    What
    Intro to Qt Concurrent

    Why
    Its very easy
    Removes the complexity of threading
    Baked right into Qt

    How
    QtConcurrent

*/

#include <QCoreApplication>
#include <QtConcurrent>

int do_map(int value)
{
    qInfo() << "Do stuff: " << value;
    int num = value * 10;
    return num;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> values;
    for(int i = 0; i < 9; i++)
    {
        values << i;
    }

    qInfo() << "Starting...";
    QList<int> updated = QtConcurrent::blockingMapped(values,&do_map);
    qInfo() << "Finished";
    qInfo() << updated;


    return a.exec();
}
