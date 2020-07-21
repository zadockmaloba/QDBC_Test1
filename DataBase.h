#pragma once

#include <QtSql/qtsqlglobal.h>
#include <QtSql/qsqldatabase.h>
#include <QtSql/qsqlquery.h>
#include <QtSql/qsqlquerymodel.h>
#include <QtCore/qdebug.h>
#include <string>
#include <QtCore/qdatetime.h>
#include <QtSql/qsqlerror.h>

class DataBase 
{
public:
	DataBase(char* path, QString conName);
	~DataBase();
	bool connectDB();
	void closeDB();
	void createDB();
	void createTable();
public:
	QSqlDatabase asDb;
	QSqlQuery* qry = new QSqlQuery();
	QSqlQueryModel* mdl = new QSqlQueryModel();
private:
};

inline DataBase::DataBase(char* path, QString conName) : asDb(QSqlDatabase::addDatabase("QPSQL"))
{
	asDb.setHostName("localhost");
	asDb.setPort(9000);
	asDb.setPassword("maloba");
	asDb.setUserName("postgres");
	asDb.setDatabaseName("QtSQLtest");
	this->connectDB();
	QSqlQuery lcd(asDb);
	lcd.exec("CREATE TABLE IF NOT EXISTS depo(a int ,b int,c int)");
	QSqlError error = lcd.lastError();
	qDebug() << error;
	this->closeDB();
}

inline DataBase::~DataBase()
{
	delete(qry);
	delete(mdl);
}

inline bool DataBase::connectDB()
{
	
	if (asDb.open())
	{
		qDebug() << "DB opened successfully";
		qDebug() << asDb.tables();
		qDebug() << asDb.connectOptions();
		return false;
	}
	return true;
}

inline void DataBase::closeDB()
{
	asDb.close();
}

