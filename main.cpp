#include "qdbc_test1.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDBC_Test1 w;
    w.show();
    return a.exec();
}
