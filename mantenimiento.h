#ifndef MANTENIMIENTO_H
#define MANTENIMIENTO_H

#include <QWidget>
#include "test.h"
#include "wiringPi.h"
#include <QThread>
//#include <threadsensores.h>

namespace Ui {
class Mantenimiento;
}

class Mantenimiento : public QWidget
{
    Q_OBJECT

public:
    explicit Mantenimiento(QWidget *parent = 0);
    ~Mantenimiento();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

private:
    Ui::Mantenimiento *ui;
    ThreadSensores *qt;
};

#endif // MANTENIMIENTO_H
