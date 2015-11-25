#ifndef INGRESO_H
#define INGRESO_H

#include <QWidget>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include "pantallaprincipal.h"

namespace Ui {
class ingreso;
}

class ingreso : public QWidget
{
    Q_OBJECT

public:
    explicit ingreso(QWidget *parent = 0);
    ~ingreso();

    QString nombre, apellido1, apellido2;
    QSqlDatabase db;
    void connClose(){
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen(){
        QString nombre;
        nombre.append("/home/pi/Desktop/PRUEBAS/BASE DE DATOS/SCOMAR.db3");
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(nombre);
        if(!db.open())
            return false;
        else
            return true;
    }

private slots:
    void on_pushButton_clicked();

private:
    Ui::ingreso *ui;
};

#endif // INGRESO_H
