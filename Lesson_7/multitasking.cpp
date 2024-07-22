#include "multitasking.h"
#include "ui_multitasking.h"

Multitasking::Multitasking(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Multitasking)
{
    ui->setupUi(this);
    m_managerThread = new QThread();
    m_manager = new Manager();

    m_manager->moveToThread(m_managerThread);
    m_managerThread->start();

    connect (m_manager, &Manager::threadsOnline, this, &Multitasking::showThreadsAmount);
    connect (ui->b_start, &QPushButton::clicked, this, &Multitasking::start);
}

Multitasking::~Multitasking()
{
    delete ui;
}

void Multitasking::start()
{
    m_manager->newTask(5, 0, 1000);
    m_manager->start();
}

void Multitasking::showThreadsAmount(int amount)
{
    ui->lcd_threads->display(amount);
}
