#include "commandline.h"

CommandLine::CommandLine(QObject *parent, FILE *fileHandler) : QObject(parent), cin(fileHandler)
{

}

void CommandLine::monitor()
{
    while(true)
    {
        QString value = cin.readLine();
        emit command(value);
    }
}
