/*

  What
  Build Qt Static

  Why
  Some people want to do things the hard way

  How

  Install the source
  https://www.youtube.com/watch?v=2qsR8Dw8uzA

Dynamic Build Commands:
./configure -release -opensource -confirm-license -prefix /PATH/BUILD
make -j8
make install

Static Build Commands:
./configure -release -static -opensource -confirm-license -prefix /PATH/BUILD-STATIC
make -j8
make install


 */

#include <QCoreApplication>
#include <QDebug>

/*
https://retifrav.github.io/blog/2018/02/17/build-qt-statically/

Can be frustrating
Takes a long time
Fully of bugs issues and show stoppers


cd /home/rootshell/Applications
mkdir build

Copy the source

<PATH TO QT>/Src/configure -static -release -ltcg -optimize-size -no-pch -prefix "<PATH TO BUILD FOLDER>/<VERSION>-static" -skip webengine -nomake tools -nomake tests -nomake examples

make -j8
(30 minutes later)
make -j8 install

Copy to Qt Folder
Setup a project and build dynamically
Manage kits
Add the Desktop Static Build
Switch the kit to static and build
** Besure to set to local desktop
** Be sure to add the Qt version (static) or it will build dynamically

Compiler - GCC 7 v86 64

build static release
run ldd and show the lack of depends and show the size difference

ldd <PATH TO BINARY>

Show the size (Hello world is 2.5 mb)
use UPX to compress

./upx -9 <PATH TO BINARY> (About 1mb)


 */

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
