#include "multitasking.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Multitasking w;
    w.show();
    return a.exec();
}
