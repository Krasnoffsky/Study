#ifndef DATABASE_H
#define DATABASE_H

#include "QtSql/QSqlDatabase"
#include "QSqlQuery"


class database
{
public:
    database();
    void updateDatabase();
    void addToDatabase();
    void deleteFromDatabase();
    void initDatabase();
    QSqlDatabase* db;
    QSqlQuery* query;

};

#endif // DATABASE_H
