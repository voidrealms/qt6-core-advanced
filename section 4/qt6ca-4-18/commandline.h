#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <QObject>
#include <QDebug>
#include <QTextStream>

class CommandLine : public QObject
{
    Q_OBJECT
public:
    explicit CommandLine(QObject *parent = nullptr, FILE *fileHandler = nullptr);

    [[noreturn]] void monitor();

signals:
    void command(QString value);

private:
    QTextStream cin;

};

#endif // COMMANDLINE_H
