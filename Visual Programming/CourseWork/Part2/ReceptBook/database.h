#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDebug>

#define DATABASE_NAME "C:\\Study\\Visual Programming\\CourseWork\\Part2\\ReceptBook\\database.db"
#define TABLE_NAME "book"
#define FIELD_NAME "name"
#define FIELD_INGREDIENTS "ingredients"
#define FIELD_RECIPE "recipe"
#define FIELD_BEST "best"

class database
{
public:
    database();

    bool addToDatabase(const QString &name, const QString &ingredients, const QString &recipe);
    bool deleteFromDatabase(const QString element);

private:

    bool openDatabase();
    bool restoreDatabase();
    void closeDatabase();
    bool createTable();

    QSqlDatabase db;

};

#endif // DATABASE_H
