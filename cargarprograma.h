#ifndef CARGARPROGRAMA_H
#define CARGARPROGRAMA_H

#include <QMainWindow>
#include <QDir>
#include <QDebug>
#include <QRegExp>
#include <QFileSystemModel>
#include <QSplitter>
//#include <qfilesystemmodel.h>
#include "moduloprogramacion.h"
#include "guardararchivo.h"
#include "copiararchivo.h"
//#include "ingreso.h"

namespace Ui {
class cargarPrograma;
}

class cargarPrograma : public QMainWindow
{
    Q_OBJECT

public:
    explicit cargarPrograma(QWidget *parent = 0);
    ~cargarPrograma();
    QString archivoLista;

private slots:
    void on_actionNuevo_triggered();
    void on_actionEditar_triggered();
    void on_actionSalir_triggered();
    void on_actionCopiar_triggered();
    void on_actionEliminar_triggered();
    void mostrarArchivo(QString);
    void on_listView_clicked(const QModelIndex &index);
    void on_pushButton_clicked();

    void on_listCorte_clicked(const QModelIndex &index);

signals:
    void archivoChanged(QString);

private:
    Ui::cargarPrograma *ui;
    QStringList List;
    QString rutaDisenos,rutaCortes;
    QString fileName;
    //QFileSystemModel *model;

};

#endif // CARGARPROGRAMA_H
