/*

  What
  Data class

  Why
  Its easy!

  How
  Code

*/

#include <QCoreApplication>
#include <QObject>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include "user.h"

bool openDB(QSqlDatabase &db)
{
    qInfo() << "Opening Database";
    db.setHostName("localhost");
    db.setUserName("qt6ca"); //Change the username
    db.setPassword("qt6ca-password"); //Change the password

    bool ok = db.open();
    if(ok)
    {
        qInfo() << "Opened database connection!";
        return true;
    }

    qInfo() << "Failed to open connection!";
    qInfo() << db.lastError().text();

    return false;
}

int createUser()
{
    qInfo() << "Creating user";
    User user;
    int id = 0;

    if(user.open())
    {
        user.begin();
        user.name = "Britney Dibel";
        user.age = 26;
        user.save();

        user.name = "Britney Crawford";
        user.save();
        user.commit();

        id = user.id;

    }

    return id;
}

void loadUser(int id)
{
    qInfo() << "Loading user:" << id;
    User user;
    if(user.open())
    {
        user.load(id);
        qInfo() << "Loaded: " << user.name;
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    if(openDB(db))
    {
       int id = createUser();
       qInfo() << "Created: " << id;

       if(id > 0) loadUser(id);

    }

    QSqlDatabase::database().close();


    return a.exec();
}
