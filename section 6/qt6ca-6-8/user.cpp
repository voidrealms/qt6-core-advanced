#include "user.h"

User::User(QObject *parent) : QObject(parent)
{
    create();
}

void User::begin()
{
    QSqlDatabase::database().transaction();
}

void User::commit()
{
    QSqlDatabase::database().commit();
}

void User::rollback()
{
    QSqlDatabase::database().rollback();
}

bool User::open()
{
    QSqlDatabase db = QSqlDatabase::database();
    bool isOpen = db.isOpen();

    qInfo() << "isOpen: " << isOpen;
    return isOpen;
}

void User::create()
{
    id = 0;
    age = 0;
    name = "";
}

void User::load(int value)
{
    qInfo() << "Loading record: " << value;

    QSqlQuery query;
    QString cmd = "SELECT idusers,age,name FROM voidrealms.users where idusers = :id;";
    query.prepare(cmd);
    query.bindValue(":id",value);

    bool ok = exec(query);

    if(ok)
    {
        while (query.next())
        {
            QSqlRecord record = query.record();
            id = record.value(0).toInt();
            age = record.value(1).toInt();
            name = record.value(2).toString();

            qInfo() << "Loaded " << id;

            return;
        }
    }
}

void User::save()
{
    if(id > 0)
    {
        update();
    }
    else
    {
        insert();
    }
}

void User::remove()
{
    QSqlQuery query;
    QString cmd = "DELETE FROM voidrealms.users where idusers = :id";
    query.prepare(cmd);
    query.bindValue(":id", id);

    exec(query);
}

bool User::insert()
{
    qInfo() << "Inserting row";
    QSqlQuery query;
    QString cmd = "INSERT INTO `voidrealms`.`users` (`name`,`age`)VALUES(:name,:age);";
    query.prepare(cmd);
    query.bindValue(":name", name);
    query.bindValue(":age", age);

    bool ok = exec(query);

    if(ok)
    {
        id = query.lastInsertId().toInt();
        qInfo() << "Inserted " << id;
    }
    else
    {
        id = 0;
    }

    return ok;
}

bool User::update()
{
    qInfo() << "Inserting row";
    QSqlQuery query;
    QString cmd = "UPDATE `voidrealms`.`users` SET `idusers` = :id, `name` = :name, `age` = :age WHERE `idusers` = :id;";
    query.prepare(cmd);
    query.bindValue(":id", id);
    query.bindValue(":name", name);
    query.bindValue(":age", age);


    bool ok = exec(query);

    if(ok)
    {
        qInfo() << "Updated " << id;
    }


    return ok;
}

bool User::exec(QSqlQuery &query)
{
    QSqlDatabase db = QSqlDatabase::database();
    if(!db.isOpen())
    {
        qInfo() << "The connection is not open!";
        return false;
    }

    qInfo() << "Exec: " << query.executedQuery();
    bool ok =  query.exec();

    if(!ok)
    {
        qInfo() << db.lastError().text();
        qInfo() << query.lastError().text();
    }

    return ok;
}
