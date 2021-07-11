/*

  What
  Assignment

  Why
  Practice what you have learned

  How
  List if the installed drivers

 */

#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Inspecting Drivers";

    foreach(QString driver, QSqlDatabase::drivers())
    {
        qInfo() << driver;

        QSqlDatabase db = QSqlDatabase::addDatabase(driver);
        QSqlDriver *obj = db.driver();

        qInfo() << "Transactions: " << obj->hasFeature(QSqlDriver::DriverFeature::Transactions);


        qInfo() << "";
    }

    return a.exec();
}
