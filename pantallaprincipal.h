#ifndef PANTALLAPRINCIPAL_H
#define PANTALLAPRINCIPAL_H

#include <QMainWindow>
#include "ingreso.h"
#include "cantidad.h"
#include "modificarciclos.h"
#include "cargarprograma.h"
#include "threadsensores.h"
#include "mantenimiento.h"
#include <QDebug>
#include <QMessageBox>
#include "wiringPi.h"

namespace Ui {
class pantallaPrincipal;
}

class pantallaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit pantallaPrincipal(QWidget *parent = 0);
    ~pantallaPrincipal();
    int cantidadActual;
    int cantidadProg;
    void configGPIO();
    void definirSalidas(QString data, QString sentido);
    QString Sensor1, Sensor2;
    cantidad *cant;
    ThreadSensores *Sensores;
    modificarCiclos *ciclo;
    cargarPrograma *CargarPrograma;
    QMessageBox msgBox;
    void lecturaSensores();

public slots:
    void abrirCargarPrograma();
    void VerPrograma(QString);
    void progCantidad(int);
    void leerPrograma(QString);
    void progCiclos(QStringList list){
        strList.clear();
        strList << list;
    }
    void cambiarContLineas(int linea){
        contLineas = linea;
    }
    void actualizarCantidadFaltante(int cantidadFaltante);
    void definirObjetos();

private slots:
    void on_pushButton_9_clicked();
    void on_pushButton_clicked();
    void on_pushButton_10_clicked(bool checked);
    void on_pushButton_11_clicked();
    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

signals:
    void sensorIzqChanged(QString);
    void sensorDerChanged(QString);
    void sensorChanged(QString);

private:
    Ui::pantallaPrincipal *ui;
    QString rutaProgramas;
    QString NombreArchivo;
    int contLineas;
    QStringList strList;
    QStringList rowData, salidas;
    int sensorDer, sensorIzq, error, contaCiclos;
    int vel1,vel2,vel3,gui1,gui2,gui3,gui4,llaDel,llaDelMed,llaTra,llaTraMed,ronDelDer,ronTraDer,ronDelIzq,ronTraIzq;
    QString inputstate;
    QString nombrePrograma;
};

#endif // PANTALLAPRINCIPAL_H
