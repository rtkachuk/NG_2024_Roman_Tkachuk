#include "worker.h"

Worker::Worker(QObject *parent)
    : QThread{parent}
{
    m_debug = false;
}

void Worker::run()
{
    for (int current = m_min; current < m_max; current++) {
        if (m_debug)
            qDebug() << "ID #" << m_id << ": " << current;
        emit progress((current - m_min) / ((m_max - m_min)/100));
        msleep(m_timeout);
    }
    emit progress(100);
}
