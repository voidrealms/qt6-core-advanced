/*

  What
  Deploy to Windows

  Why
  Its windows

  How

make new app
choose mingw x 64


--------------------
#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

#ifdef QT_DEBUG
    qInfo() << "Running in debug build";
#else
    qInfo() << "Running in release build";
#endif

    return a.exec();
}
--------------------

build in release
show the exe

Run windeploy qt
<PATH TO QT>\mingw73_64\bin\windeployqt.exe "<PATH TO BINARY>"

Run it and show its still having issues
Show Dependancy walker and show the yellow items

 Still missing
    LIBGCC_S_DW2-1.DLL
    LIBSTDC++-6.DLL

    Look in the Ming32Bit folder
    C:\Qt\5.12.2\mingw73_32\bin

Copy the yellow libs
Show the EXE runs

// My favorite tool is INNO Setup

 */


#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

#ifdef QT_DEBUG
    qInfo() << "Running in debug build";
#else
    qInfo() << "Running in release build";
#endif

    return a.exec();
}
