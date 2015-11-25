#ifndef MODIFICARCICLOS_H
#define MODIFICARCICLOS_H

#include <QWidget>
#include <qspinbox.h>

namespace Ui {
class modificarCiclos;
}

class modificarCiclos : public QWidget
{
    Q_OBJECT

public:
    explicit modificarCiclos(QWidget *parent = 0);
    ~modificarCiclos();
    void cargarCiclos(QStringList);
    int fila, columna;

public slots:
    void EditarCelda();

signals:
    void ciclosChanged(QStringList);

private slots:
    void spinBoxChange(int value);
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::modificarCiclos *ui;
    QStringList data;
    QStringList rowData;
    QStringList datosLista;
};

#endif // MODIFICARCICLOS_H
