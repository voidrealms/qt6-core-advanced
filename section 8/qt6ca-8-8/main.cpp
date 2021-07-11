/*

  What
  Deploy to linux

  Why
  This can get crazy...

  How
    Run LinuxQtDeploy
    https://github.com/probonopd/linuxdeployqt


    export LD_LIBRARY_PATH=/home/rootshell/Applications/Qt/6.1.1/gcc_64/lib/
    ./linuxdeployqt-continuous-x86_64.AppImage ./build/qt6ca-8-8 -unsupported-allow-new-glibc

    copy the icon.png

    Make a desktop file (your_app.desktop)
    ------------------
[Desktop Entry]
Type=Application
Name=MyApp
Comment=Qt Tutorial
Exec=qt6ca-8-8
Icon=icon
Categories=Office;
    ------------------

    Run app image
    https://github.com/AppImage/AppImageKit
    https://github.com/AppImage/AppImageKit/releases

./appimagetool-x86_64.AppImage ./build/


 */


#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

#ifdef QT_DEBUG
  qDebug() << "Running a debug build";
#else
  qDebug() << "Running a release build";
#endif

    return a.exec();
}
