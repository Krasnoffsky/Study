#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDebug>
#include <QObject>

#define DATABASE_NAME "C:\\Study\\Visual Programming\\CourseWork\\Part2\\ReceptBook\\database.db"
#define TABLE_NAME "book"
#define FIELD_ID "_id"
#define FIELD_NAME "name"
#define FIELD_INGREDIENTS "ingredients"
#define FIELD_RECIPE "recipe"
#define FIELD_TYPE "type"
#define FIELD_BEST "best"
#define FIELD_PIC "pic"

class database : public QObject
{
Q_OBJECT

public:
    database();

    bool addToDatabase(const QString &name, const QString &ingredients, const QString &recipe, const QString &type, const QString &best, const QByteArray &pic);
    bool deleteFromDatabase(const int id);
    bool editInDatabase(const int &id, const QString &name, const QString &ingredients, const QString &recipe, const QString &type, const QByteArray &pic);
    bool editBestInDatabase(const int id, const int flag);

private:

    bool openDatabase();
    bool restoreDatabase();
    void closeDatabase();
    bool createTable();

    QSqlDatabase db;

};

#endif // DATABASE_H
