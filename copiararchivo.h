#ifndef COPIARARCHIVO_H
#define COPIARARCHIVO_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class copiarArchivo;
}

class copiarArchivo : public QWidget
{
    Q_OBJECT

public:
    explicit copiarArchivo(QWidget *parent = 0);
    ~copiarArchivo();
    void setRuta(QString ruta);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::copiarArchivo *ui;
    QString rutaOrigen, rutaCopia;
};

#endif // COPIARARCHIVO_H
