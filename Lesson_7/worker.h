#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>
#include <QDebug>

class Worker : public QThread
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    void setMin(int min) { m_min = min; }
    void setMax(int max) { m_max = max; }
    void setTimeout(int timeout) { m_timeout = timeout; }
    void setId(QString id) { m_id = id; }
    void setDebug(bool mode) { m_debug = mode; }

    QString getId() { return m_id; }

signals:
    void progress(int);

protected:
    virtual void run();

private:
    int m_min = -1;
    int m_max = -1;
    int m_timeout = 0;
    QString m_id;
    bool m_debug;
};

#endif // WORKER_H
