#include "qdbc_test1.h"

QDBC_Test1::QDBC_Test1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->innitDB();
    QString com1("Insert into Student_info(firstname, secondname, indexnum) values ('Zadock','maloba',1234) ");
    execQuery(com1);
}

QDBC_Test1::~QDBC_Test1()
{
    delete(xDB);
}

bool QDBC_Test1::execQuery(QString cmd)
{
    xDB->connectDB();
    QSqlQuery exQry(xDB->asDb);
    if (!exQry.exec(cmd))
    {
        QSqlError error = exQry.lastError();
        qDebug() << error;
        return false;
    }
    return true;
}

void QDBC_Test1::innitDB()
{
    xDB->connectDB();
    QSqlQuery nqry(xDB->asDb);
    if (!nqry.exec("CREATE TABLE IF NOT EXISTS Student_info (firstname char(20), secondname char(20), indexnum int);")) {
        QSqlError error = nqry.lastError();
        qDebug() << error;
    }
    else
    {
        qDebug() << "Table created succesfully";
    }
    xDB->closeDB();
}
