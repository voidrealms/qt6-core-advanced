#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>
#include <QFuture>
#include <QFutureWatcher>
#include <QMutex>
#include <QtConcurrent>
#include <QThread>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

    void process();
    static void multiply(int &value);

signals:
public slots:
    void canceled();
    void finished();
    void suspending();
    void suspended();
    void progressRangeChanged(int minimum, int maximum);
    void progressTextChanged(const QString &progressText);
    void progressValueChanged(int progressValue);
    void resultReadyAt(int index);
    void resultsReadyAt(int beginIndex, int endIndex);
    void resumed();
    void started();

private:
    QFutureWatcher<void> watcher;
    QFuture<void> future;
    QList<int> list;

};

#endif // TEST_H
