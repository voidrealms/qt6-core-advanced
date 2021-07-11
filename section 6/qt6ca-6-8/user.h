#ifndef USER_H
#define USER_H

#include <QObject>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr);

    int id;
    int age;
    QString name;

    void begin();
    void commit();
    void rollback();
    bool open();
    void create();
    void load(int value);
    void save();
    void remove();


signals:

public slots:

private:
    bool insert();
    bool update();
    bool exec(QSqlQuery &query);
};

#endif // USER_H
