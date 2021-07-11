/*

  What
  Test app to deploy

  Why
  We want to distribute our app

  How

    Deploy on mac example

    https://doc.qt.io/qt-5/macos-deployment.html

    Compile in debug mode
    Compile in release mode

    Show how these are different applications, different sizes using the Get Info

    use otool to show the dependancies
    otool -L <PATH TO BINARY>

    open a application - Calculator
    right click and "Show Package Contents"
    Talk about how they can be self contained and have an expected format

    Look in the pro file
    CONFIG -= app_bundle
    comment out and show the bundle being created, but it lacks the qt libs, use show contents on it
    #CONFIG -= app_bundle

    CMAKE
set(CUR_TARGET myappname)
add_executable(${CUR_TARGET} MACOSX_BUNDLE ${MY_SRC})
set_target_properties(${CUR_TARGET} PROPERTIES
    BUNDLE True
    MACOSX_BUNDLE_GUI_IDENTIFIER my.domain.style.identifier.${CUR_TARGET}
    MACOSX_BUNDLE_BUNDLE_NAME ${CUR_TARGET}
    MACOSX_BUNDLE_BUNDLE_VERSION "0.1"
    MACOSX_BUNDLE_SHORT_VERSION_STRING "0.1"
    MACOSX_BUNDLE_INFO_PLIST ${CMAKE_SOURCE_DIR}/cmake/customtemplate.plist.in
)
-----------------------
add_executable(qt6ca-8-7 MACOSX_BUNDLE
  main.cpp
)
set_target_properties(qt6ca-8-7 PROPERTIES
    BUNDLE True
    MACOSX_BUNDLE_GUI_IDENTIFIER my.domain.style.identifier.qt6ca-8-7
    MACOSX_BUNDLE_BUNDLE_NAME qt6ca-8-7
    MACOSX_BUNDLE_BUNDLE_VERSION "0.1"
    MACOSX_BUNDLE_SHORT_VERSION_STRING "0.1"
    #MACOSX_BUNDLE_INFO_PLIST ${CMAKE_SOURCE_DIR}/cmake/customtemplate.plist.in

)
-----------------------


    Look in <PATH TO QT>/clang_64/bin/

    show "macdeployqt"
    run <PATH TO QT>clang_64/bin/macdeployqt <PATH TO APP PACKAGE> -dmg

    Examine the app inside of the bundle
    otool -L <PATH TO BINARY>
    Run the app from inside the bundle

    Run the app using open
    open -a Terminal <PATH TO APP PACKAGE>

 */

#include <QCoreApplication>
#include <QDebug>


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
