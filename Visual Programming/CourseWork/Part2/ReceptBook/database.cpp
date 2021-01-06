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

    query = new QSqlQuery(*db);

}

void database::updateDatabase()
{
    query->clear();
    query->exec("SELECT name, age, color FROM test");
}

void database::addToDatabase()
{
    int testing = 15;
    query->clear();
    query->prepare("INSERT INTO test VALUES ('Paul',?,'green');");
    query->addBindValue(testing);
    db->transaction();
        if (!query->execBatch(QSqlQuery::ValuesAsColumns))
        {
            qDebug()<<"request"<<query->executedQuery();
            db->rollback();
        }
        else
        {
           db->commit();
        }
}
