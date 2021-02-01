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
                    FIELD_ID " INTEGER PRIMARY KEY AUTOINCREMENT, "
                    FIELD_NAME     " TEXT    NOT NULL,"
                    FIELD_INGREDIENTS     " TEXT    NOT NULL,"
                    FIELD_RECIPE       " TEXT    NOT NULL"
                    FIELD_TYPE       " TEXT    NOT NULL"
                    FIELD_BEST     " TEXT    NOT NULL,"
                    FIELD_PIC     " BLOB    NOT NULL"
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

bool database::addToDatabase(const QString &name, const QString &ingredients, const QString &recipe, const QString &type, const QString &best, const QByteArray &pic)
{

    QSqlQuery query(db);

    query.prepare("INSERT INTO " TABLE_NAME " ( "
                                FIELD_NAME ", "
                                FIELD_INGREDIENTS ", "
                                FIELD_RECIPE " , "
                                FIELD_TYPE ", "
                                FIELD_BEST ", "
                                FIELD_PIC " ) "
                                "VALUES (?, ?, ?, ?, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(ingredients);
    query.addBindValue(recipe);
    query.addBindValue(type);
    query.addBindValue(best);
    query.addBindValue(pic);


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

bool database::editInDatabase(const int &id, const QString &name, const QString &ingredients, const QString &recipe, const QString &type, const QByteArray &pic)
{
    QSqlQuery query(db);

    query.prepare("UPDATE " TABLE_NAME " SET "
                            FIELD_NAME "=:NAME, "
                            FIELD_INGREDIENTS "=:INGREDIENTS, "
                            FIELD_RECIPE "=:RECIPE, "
                            FIELD_TYPE "=:TYPE, "
                            FIELD_PIC "=:PIC "
                            "WHERE " FIELD_ID "=:ID");

    query.bindValue(":NAME", name);
    query.bindValue(":INGREDIENTS", ingredients);
    query.bindValue(":RECIPE", recipe);
    query.bindValue(":TYPE", type);
    query.bindValue(":PIC", pic);
    query.bindValue(":ID", id);

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

