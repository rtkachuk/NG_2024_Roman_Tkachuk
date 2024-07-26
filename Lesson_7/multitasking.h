#ifndef MULTITASKING_H
#define MULTITASKING_H

#include <QMainWindow>
#include <QThread>
#include <QProgressBar>
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
    void getWorkerProgress(QPair<QString, int> status);

private:
    Ui::Multitasking *ui;
    Manager *m_manager;
    QThread *m_managerThread;

    QMap<QString, QProgressBar*> m_threadsProgressWidgets;

};
#endif // MULTITASKING_H
