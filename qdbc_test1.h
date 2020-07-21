#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qdbc_test1.h"
#include "DataBase.h"

class QDBC_Test1 : public QMainWindow
{
    Q_OBJECT

public:
    QDBC_Test1(QWidget *parent = Q_NULLPTR);
    ~QDBC_Test1();

private:
    Ui::QDBC_Test1Class ui;
    DataBase* xDB = new DataBase("testing123.odb", "connA");
    void innitDB();
};
