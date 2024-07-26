#include "manager.h"

Manager::Manager(QObject *parent)
    : QObject{parent}
{
}

void Manager::initJobs(int workerAmount, int min, int max)
{
    int taskPerWorker = (max - min) / workerAmount;
    for (int workerNumber = 0; workerNumber < workerAmount; workerNumber++) {
        Worker *worker = new Worker();
        worker->setMin(min + (taskPerWorker * workerNumber));
        worker->setMax(min + (taskPerWorker * (workerNumber + 1)));
        worker->setTimeout(50 * (workerNumber + 1));
        worker->setId(QString::number(workerNumber));

        m_workerGroup.push_back(worker);

        connect (worker, &QThread::finished, this, &Manager::threadFinished);
        connect (worker, &Worker::progress, this, &Manager::threadProgress);
    }
}

void Manager::start(int workerAmount, int min, int max)
{
    if (m_workerGroup.size() > 0) {
        qDebug() << "Already started! Wait for completion";
        return;
    }

    initJobs(workerAmount, min, max);

    for (Worker *worker : m_workerGroup) {
        worker->start();
        qDebug() << "[Manager]: Worker " << worker->getId() << " started!";
    }

    emit threadsOnline(m_workerGroup.size());
}

void Manager::threadFinished()
{
    Worker *worker = (Worker *)sender();

    m_workerGroup.removeAll(worker);
    delete worker;

    emit threadsOnline(m_workerGroup.size());
}

void Manager::threadProgress(int progress)
{
    Worker *worker = (Worker *)sender();
    qDebug() << "[Progress] " << worker->getId() << ": " << progress << "%";

    QPair <QString, int> workerData(worker->getId(), progress);
    emit workerProgress(workerData);
}
