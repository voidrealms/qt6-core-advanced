/*

  What
  QSqlDatabase and QSqlQuery

  Why
  We want the basics of how to work with MySql

  How
  Example below

 */

#include <QCoreApplication>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QPluginLoader>
#include <QVariant>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Opening the database";
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost"); // 127.0.0.1
    db.setUserName("qt6ca");  //Change the username
    db.setPassword("qt6ca-password"); //Change the password

    if(!db.open())
    {
        qInfo() << "Could not open connection!";
        qInfo() << db.lastError().text();
    }
    else
    {
        qInfo() << "Connected, lets make a query...";
        QSqlQuery query;
        QString cmd = "SELECT name,age FROM voidrealms.users WHERE age > 40;";

        if(!query.exec(cmd))
        {
            qInfo() << db.lastError().text();
            qInfo() << query.lastError().text();
        }
        else
        {
            qInfo() << "Got query results: " << query.size();
            while(query.next())
            {
                QString name = query.value(0).toString();
                int age = query.value(1).toInt();

                qInfo() << " name: " << name << " is " << age;
            }
        }

        db.close();
        qInfo() << "Disconnected";

    }


    return a.exec();
}
