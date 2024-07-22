#include "worker.h"

Worker::Worker(QObject *parent)
    : QThread{parent}
{}

void Worker::run()
{
    for (int current = m_min; current < m_max; current++) {
        qDebug() << "ID #" << m_id << ": " << current;
        msleep(m_timeout);
    }
}
