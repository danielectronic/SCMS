#ifndef THREADSENSORES_H
#define THREADSENSORES_H

#include <QThread>

class ThreadSensores : public QThread
{
    Q_OBJECT
public:
    explicit ThreadSensores(QObject *parent = 0);
    explicit ThreadSensores(QString *h);
    void run();
    void stop();
    void sleep(int valor);

signals:
    void sensorChanged(QString);

public slots:

private:
int S1,S2;
};

#endif // THREADSENSORES_H
