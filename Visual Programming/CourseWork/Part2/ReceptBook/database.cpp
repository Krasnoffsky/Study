#include "database.h"

database::database()
{
    initDatabase();
}

void database::initDatabase()
{
    db = new QSqlDatabase;
    *db = QSqlDatabase::addDatabase("QSQLITE");
    db->setDatabaseName("C:\\Study\\Visual Programming\\CourseWork\\Part2\\ReceptBook\\database.db");
    db->open();

    query = new QSqlQuery;

}

void database::updateDatabase()
{
    query->exec("SELECT name, age, color FROM test");
}

void database::addToDatabase()
{

}
