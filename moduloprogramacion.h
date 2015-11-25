#ifndef MODULOPROGRAMACION_H
#define MODULOPROGRAMACION_H

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QDebug>

namespace Ui {
class moduloProgramacion;
}

class moduloProgramacion : public QMainWindow
{
    Q_OBJECT

public:
    explicit moduloProgramacion(QWidget *parent = 0);
    ~moduloProgramacion();
    QString rutaArchivo;
    void CargarArchivo();
    int fila, columna;

private slots:
    void on_actionGuardar_Programa_triggered();
    void on_actionInsertar_Linea_triggered();
    void spinBoxChange(int value);

    void on_actionSalir_triggered();

    void on_actionEliminar_Linea_triggered();

    void on_actionInsertar_Corte_triggered();

public slots:
    void EditarCelda();

private:
    Ui::moduloProgramacion *ui;
};

#endif // MODULOPROGRAMACION_H
