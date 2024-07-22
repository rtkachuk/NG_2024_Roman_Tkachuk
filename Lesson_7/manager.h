#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QTimer>
#include "worker.h"

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);
    void newTask(int workerAmount, int min, int max);

public slots:
    void start();

private slots:
    void tick();

signals:
    void threadsOnline(int amount);

private:
    int getActiveThreads();

    QMap<int, Worker*> m_workerGroup;
    QTimer *m_timer;
};

#endif // MANAGER_H
