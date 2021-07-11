#include "test.h"

Test::Test(QObject *parent) : QObject(parent)
{
    //Connect
       /*
       void canceled();
       void finished();
       void paused();
       void progressRangeChanged(int minimum, int maximum);
       void progressTextChanged(const QString &progressText);
       void progressValueChanged(int progressValue);
       void resultReadyAt(int index);
       void resultsReadyAt(int beginIndex, int endIndex);
       void resumed();
       void started();
       */

       connect(&watcher, &QFutureWatcher<void>::canceled, this, &Test::canceled);
       connect(&watcher, &QFutureWatcher<void>::finished, this, &Test::finished);

       //Qt5
       //connect(&watcher, &QFutureWatcher<void>::paused, this, &Test::paused);

       connect(&watcher, &QFutureWatcher<void>::suspending, this, &Test::suspending);
       connect(&watcher, &QFutureWatcher<void>::suspended, this, &Test::suspended);

       connect(&watcher, &QFutureWatcher<void>::progressRangeChanged, this, &Test::progressRangeChanged);
       connect(&watcher, &QFutureWatcher<void>::progressTextChanged, this, &Test::progressTextChanged);
       connect(&watcher, &QFutureWatcher<void>::progressValueChanged, this, &Test::progressValueChanged);
       connect(&watcher, &QFutureWatcher<void>::resultReadyAt, this, &Test::resultReadyAt);
       connect(&watcher, &QFutureWatcher<void>::resumed, this, &Test::resumed);
       connect(&watcher, &QFutureWatcher<void>::started, this, &Test::started);

}

void Test::process()
{
    QMutex mutex;
    mutex.lock();
    list.clear();
    for(int i = 0; i < 100; i++)
    {
        list.append(i);
    }
    mutex.unlock();

    future = QtConcurrent::map(list,&Test::multiply);
    watcher.setFuture(future);
}

void Test::multiply(int &value)
{
    qInfo() << "Called" << value;
    value = value * 10;

    //Slow this down
    QThread::currentThread()->msleep(250);
}

void Test::canceled()
{
    qInfo() << "Canceled";
}

void Test::finished()
{
    qInfo() << "Finished";
    qInfo() << list;
}

void Test::suspending()
{
    qInfo() << "Suspending";
}

void Test::suspended()
{
    qInfo() << "Suspended";
}

void Test::progressRangeChanged(int minimum, int maximum)
{
    qInfo() << "Range " << minimum << " to " << maximum;
}

void Test::progressTextChanged(const QString &progressText)
{
    qInfo() << "Text: " << progressText;
}

void Test::progressValueChanged(int progressValue)
{
    qInfo() << "Progress: " << progressValue;
}

void Test::resultReadyAt(int index)
{
    qInfo() << "ReadyAt: " << index;
}

void Test::resultsReadyAt(int beginIndex, int endIndex)
{
    qInfo() << "ResultsReadyAt " << beginIndex << " to " << endIndex;
}

void Test::resumed()
{
    qInfo() << "Resumed";
}

void Test::started()
{
    qInfo() << "Started";
}
