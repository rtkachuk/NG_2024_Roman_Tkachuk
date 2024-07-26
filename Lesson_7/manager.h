#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QPair>
#include "worker.h"

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);

public slots:
    void start(int workerAmount, int min, int max);

private slots:
    void threadFinished();
    void threadProgress(int progress);

signals:
    void threadsOnline(int amount);
    void workerProgress(QPair<QString, int>);

private:
    void initJobs(int workerAmount, int min, int max);

    QVector<Worker*> m_workerGroup;
};

#endif // MANAGER_H
