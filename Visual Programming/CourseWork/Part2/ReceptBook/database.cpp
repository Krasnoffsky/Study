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
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " TABLE_NAME " ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    FIELD_NAME     " VARCHAR()    NOT NULL,"
                    FIELD_INGREDIENTS     " VARCHAR()    NOT NULL,"
                    FIELD_RECIPE       " VARCHAR()    NOT NULL"
                    FIELD_TYPE       " VARCHAR()    NOT NULL"
                    FIELD_BEST     " VARCHAR()    NOT NULL,"
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

bool database::addToDatabase(const QString &name, const QString &ingredients, const QString &recipe, const QString &type, const QString &best)
{
    QVariantList data;

    data.append(name);
    data.append(ingredients);
    data.append(recipe);
    data.append(type);
    data.append(best);

    QSqlQuery query;

    while(query.next()){
        query.exec("SELECT" FIELD_NAME " FROM " TABLE_NAME);
        if (name == query.value(0).toString()){
            qDebug() << "ERROR: Record with this name already exists";
            return false;
        }
    }

//    query.clear();

    query.prepare("INSERT INTO " TABLE_NAME " ( "
                                FIELD_NAME ", "
                                FIELD_INGREDIENTS ", "
                                FIELD_RECIPE " , "
                                FIELD_TYPE ", "
                                FIELD_BEST " ) "
                                "VALUES (:Name, :Ingredients, :Recipe, :Type, :Best)");
    query.bindValue(":Name",       data[0].toString());
    query.bindValue(":Ingredients",       data[1].toString());
    query.bindValue(":Recipe",         data[2].toString());
    query.bindValue(":Type",         data[3].toString());
    query.bindValue(":Best",         data[4].toString());

    if(!query.exec()){
        qDebug() << "ERROR: Can't insert into table " << TABLE_NAME;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }

    return false;

}

bool database::deleteFromDatabase(const QString element)
{
    QSqlQuery query;

    query.prepare("DELETE FROM " TABLE_NAME " WHERE name= :NAME ;");
    query.bindValue(":NAME", element);

    if(!query.exec()){
        qDebug() << "ERROR: Can't delete from table " << TABLE_NAME;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }

    return false;

}

void database::readFromDatabase()
{
    QSqlQuery query;

    query.exec("SELECT " FIELD_NAME ", " FIELD_INGREDIENTS ", " FIELD_RECIPE ", " FIELD_TYPE " FROM " TABLE_NAME);
    while (query.next()){
        emit sendToWidget(query.value(0).toString(),
                     query.value(1).toString(),
                     query.value(2).toString(),
                     query.value(3).toString());
    }
}
