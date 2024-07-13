#include <QCoreApplication>
#include "servak.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Servak myserver;
    myserver.start("0.0.0.0", 8081);
    return a.exec();
}
