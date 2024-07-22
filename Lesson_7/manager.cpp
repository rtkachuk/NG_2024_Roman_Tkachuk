#include "manager.h"

Manager::Manager(QObject *parent)
    : QObject{parent}
{
    m_timer = new QTimer();
    m_timer->setInterval(1000);
    m_timer->start();

    connect (m_timer, &QTimer::timeout, this, &Manager::tick);

}

void Manager::newTask(int workerAmount, int min, int max)
{
    int taskPerWorker = (max - min) / workerAmount;
    for (int workerNumber = 0; workerNumber < workerAmount; workerNumber++) {
        Worker *worker = new Worker();
        worker->setMin(min + (taskPerWorker * workerNumber));
        worker->setMax(min + (taskPerWorker * (workerNumber + 1)));
        worker->setTimeout(200 * (workerNumber + 1));
        worker->setId(QString::number(workerNumber));

        m_workerGroup[workerNumber] = worker;
    }
}

void Manager::start()
{
    if (getActiveThreads() > 0) {
        qDebug() << "Already started! Wait for completion";
        return;
    }


    for (int number : m_workerGroup.keys()) {
        m_workerGroup[number]->start();
        qDebug() << "[Manager]: Worker " << number << " started!";
    }

    emit threadsOnline(m_workerGroup.keys().count());
}

void Manager::tick()
{
    qDebug() << "[Manager]: tock";
    emit threadsOnline(getActiveThreads());
}

int Manager::getActiveThreads()
{
    int runningThreads = 0;
    for (int number : m_workerGroup.keys()) {
        if (m_workerGroup[number]->isRunning()) {
            runningThreads++;
        }
    }
    return runningThreads;
}
