#include "qdbc_test1.h"

QDBC_Test1::QDBC_Test1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->innitDB();
}

QDBC_Test1::~QDBC_Test1()
{
    delete(xDB);
}

void QDBC_Test1::innitDB()
{
    xDB->connectDB();
    QSqlQuery nqry(xDB->asDb);
    nqry.exec("CREATE TABLE IF NOT EXISTS depotico (a int, b int, c int);");
    QSqlError error = nqry.lastError();
    qDebug() << error;
    xDB->closeDB();
}
