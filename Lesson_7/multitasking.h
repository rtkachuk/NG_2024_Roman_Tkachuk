#ifndef MULTITASKING_H
#define MULTITASKING_H

#include <QMainWindow>
#include <QThread>
#include "manager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Multitasking;
}
QT_END_NAMESPACE

class Multitasking : public QMainWindow
{
    Q_OBJECT

public:
    Multitasking(QWidget *parent = nullptr);
    ~Multitasking();

private slots:
    void start();
    void showThreadsAmount(int amount);

private:
    Ui::Multitasking *ui;
    Manager *m_manager;
    QThread *m_managerThread;

};
#endif // MULTITASKING_H
