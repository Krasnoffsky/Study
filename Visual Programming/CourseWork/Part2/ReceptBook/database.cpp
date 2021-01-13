#include "database.h"

database::database()
{
    if(QFile(DATABASE_NAME).exists())
        this->openDatabase();
    else
        this->restoreDatabase();

}

bool database::openDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DATABASE_NAME);
    if (db.open())
        return true;
    else
        return false;

}

bool database::restoreDatabase()
{
    if(this->openDatabase())
        return (this->createTable()) ? true : false;
    else {
        qDebug() << "ERROR: Database can't be opened";
        return false;
    }
}

bool database::createTable()
{
    QSqlQuery query(db);
    if(!query.exec( "CREATE TABLE " TABLE_NAME " ("
                    "_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    FIELD_NAME     " VARCHAR()    NOT NULL,"
                    FIELD_INGREDIENTS     " VARCHAR()    NOT NULL,"
                    FIELD_RECIPE       " VARCHAR()    NOT NULL"
                    FIELD_TYPE       " VARCHAR()    NOT NULL"
                    FIELD_BEST     " VARCHAR()    NOT NULL,"
                    FIELD_PIC     " VARCHAR()    NOT NULL"
                    " )"
     )){
        qDebug() << "ERROR: Can't create table " << TABLE_NAME;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

bool database::addToDatabase(const QString &name, const QString &ingredients, const QString &recipe, const QString &type, const QString &best, const QString &pic)
{

    QSqlQuery query(db);

    query.prepare("INSERT INTO " TABLE_NAME " ( "
                                FIELD_NAME ", "
                                FIELD_INGREDIENTS ", "
                                FIELD_RECIPE " , "
                                FIELD_TYPE ", "
                                FIELD_BEST ", "
                                FIELD_PIC " ) "
                                "VALUES (:Name, :Ingredients, :Recipe, :Type, :Best, :Pic)");
    query.bindValue(":Name", name);
    query.bindValue(":Ingredients", ingredients);
    query.bindValue(":Recipe", recipe);
    query.bindValue(":Type", type);
    query.bindValue(":Best", best);
    query.bindValue(":Pic", pic);


    if(!query.exec()){
        qDebug() << "ERROR: Can't insert into table " << TABLE_NAME;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }

    return false;

}

bool database::deleteFromDatabase(const int id)
{
    QSqlQuery query(db);

    query.prepare("DELETE FROM " TABLE_NAME " WHERE " FIELD_ID "= :ID ;");
    query.bindValue(":ID", id);

    if(!query.exec()){
        qDebug() << "ERROR: Can't delete from table " << TABLE_NAME;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }

    return false;

}

bool database::editInDatabase(const QString &id, const QString &name, const QString &ingredients, const QString &recipe, const QString &type, const QString &best, const QString &pic)
{
    QSqlQuery query(db);

    query.prepare("UPDATE " TABLE_NAME " SET "
                            FIELD_NAME "=:NAME "
                            FIELD_INGREDIENTS "=:INGREDIENTS "
                            FIELD_RECIPE "=:RECIPE "
                            FIELD_TYPE "=:TYPE "
                            FIELD_BEST "=:BEST "
                            FIELD_PIC "=:PIC "
                            "WHERE " FIELD_ID "=:ID");

    query.bindValue(":NAME", name);
    query.bindValue(":INGREDIENTS", ingredients);
    query.bindValue(":RECIPE", recipe);
    query.bindValue(":TYPE", type);
    query.bindValue(":BEST", best);
    query.bindValue(":ID", id);
    query.bindValue(":PIC", pic);

    if(!query.exec()){

        qDebug() << "ERROR: Can't edit record in table " << TABLE_NAME;
        qDebug() << query.lastError().text();
        return false;
    }
    else
        return true;

    return false;

}

bool database::editBestInDatabase(const int id, const int flag)
{
    QSqlQuery query(db);

    query.prepare("UPDATE " TABLE_NAME " SET "
                            FIELD_BEST "=:BEST "
                            "WHERE " FIELD_ID "=:ID");

    query.bindValue(":BEST", flag);
    query.bindValue(":ID", id);

    if(!query.exec()){

        qDebug() << "ERROR: Can't edit best record in table " << TABLE_NAME;
        qDebug() << query.lastError().text();
        return false;
    }
    else
        return true;

    return false;
}

