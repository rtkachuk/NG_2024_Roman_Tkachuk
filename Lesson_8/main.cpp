#include "aiaskeverything.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AIAskEverything w;
    w.show();
    return a.exec();
}
