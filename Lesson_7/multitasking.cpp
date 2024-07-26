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
    connect (m_manager, &Manager::workerProgress, this, &Multitasking::getWorkerProgress);
    connect (ui->b_start, &QPushButton::clicked, this, &Multitasking::start);
}

Multitasking::~Multitasking()
{
    delete ui;
}

void Multitasking::start()
{
    m_manager->start(ui->spinBox->value(), 0, 1000);
}

void Multitasking::showThreadsAmount(int amount)
{
    ui->lcd_threads->display(amount);
}

void Multitasking::getWorkerProgress(QPair<QString, int> status)
{
    if (m_threadsProgressWidgets.keys().contains(status.first) == false) {
        QProgressBar *progressBar = new QProgressBar();
        progressBar->setRange(0,100);
        m_threadsProgressWidgets[status.first] = progressBar;

        ui->verticalLayout->addWidget(progressBar);
        progressBar->show();
    }

    m_threadsProgressWidgets[status.first]->setValue(status.second);

    if (status.second == 100) {
        QProgressBar *progress = m_threadsProgressWidgets[status.first];
        progress->hide();
        ui->verticalLayout->removeWidget(progress);
        delete progress;
        m_threadsProgressWidgets.remove(status.first);
    }
}
