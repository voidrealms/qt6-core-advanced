/*

  What
  Testing the driver

  Why
  We want to make sure it works

  How
  Example below

  Notes

find_package(Qt6 COMPONENTS Sql REQUIRED)
target_link_libraries(mytarget PRIVATE Qt6::Sql)

READ the documentation
https://doc-snapshots.qt.io/qt6-dev/sql-driver.html#qmysql

If you have issues...

 Testing the driver
 <PATH TO QT>/clang_64/plugins/sqldrivers

 QSqlDatabase: QMYSQL driver not loaded
 Generally this means mysql driver is not there.

 Download the mysql connector
 https://dev.mysql.com/downloads/connector/c/
 https://dev.mysql.com/downloads/connector/cpp/
 Also mysql work bench

 Install MySQL on mac
 brew install mysql

WINDOWS
For me this just worked, but you may need to install the connector
https://stackoverflow.com/questions/24221466/qmysql-driver-not-loaded-on-windows


LINUX
~<PATH TO QT>/gcc_64/plugins/sqldrivers $ ldd libqsqlmysql.so
libmysqlclient.so.18 => not found
Installing the old driver works
https://launchpad.net/ubuntu/xenial/amd64/libmysqlclient18/5.6.25-0ubuntu1

MAC
http://sirspot.com/?p=283
otool -L /<PATH TO QT>/clang_64/plugins/sqldrivers/libqsqlmysql_debug.dylib
/usr/local/mysql/lib/libmysqlclient.20.dylib (compatibility version 20.0.0, current version 20.0.0)
brew uninstall mysql
brew install mysql
Installed in: /usr/local/Cellar/mysql/8.0.15

install_name_tool -change /opt/local/lib/mysql55/mysql/libmysqlclient.18.dylib /usr/local/mysql/lib/libmysqlclient.20.dylib ./libqsqlmysql.dylib

otool -L libqsqlmysql.dylib

Before
otool -L /<PATH TO QT>/clang_64/plugins/sqldrivers/libqsqlmysql_debug.dylib
/usr/local/mysql/lib/libmysqlclient.20.dylib

install_name_tool -change /usr/local/mysql/lib/libmysqlclient.20.dylib /usr/local/Cellar/mysql/8.0.15/lib/libmysqlclient.21.dylib /Users/bryancairns/Qt/5.10.1/clang_64/plugins/sqldrivers/libqsqlmysql_debug.dylib



 */

#include <QCoreApplication>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QPluginLoader>
#include <QVariant>

void connectDB()
{
    qInfo() << "Opening Database";
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("db4free.net");
    db.setDatabaseName("qt6cadb"); //Change this to your config
    db.setUserName("qt6cadb"); //Change this to your config
    db.setPassword("qt6cadb-password"); //Change this to your config

    if(!db.open())
    {
        qInfo() << "Failed to connect!";
        qInfo() << db.lastError().text();
        return;
    }

    //Do stuff once connected!

    qInfo() << "Connected!";

    db.close();
}

bool testPlugin()
{
    qInfo() << "Testing plugin";
    //QPluginLoader loader("<PATH TO QT>/gcc_64/plugins/sqldrivers/libqsqlmysql.so"); //Change this!
    QPluginLoader loader("/home/rootshell/Applications/Qt/6.1.1/gcc_64/plugins/sqldrivers/libqsqlmysql.so"); //Change this!

    qInfo() << loader.metaData();

    if(loader.load())
    {
        qInfo() << "Loaded the plugin";
        return true;
    }

    qInfo() << loader.errorString();
    return false;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(testPlugin())
    {
        connectDB();
    }

    return a.exec();
}
