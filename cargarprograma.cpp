#include "cargarprograma.h"
#include "ui_cargarprograma.h"

#include <qsortfilterproxymodel.h>

cargarPrograma::cargarPrograma(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cargarPrograma)
{
    ui->setupUi(this);
    //rutaProgramas = "F:/Universidad/PROYECTOS/SCOMAR/PROGRAMAS/";
    rutaDisenos ="/home/pi/Desktop/PRUEBAS/PROGRAMAS/DISENOS/";
    rutaCortes ="/home/pi/Desktop/PRUEBAS/PROGRAMAS/CORTES/";

    //model = new QFileSystemModel;
    QFileSystemModel *modelDiseno = new QFileSystemModel;
    modelDiseno->setRootPath(rutaDisenos);

    ui->listView->setModel(modelDiseno);
    ui->listView->setRootIndex(modelDiseno->index(rutaDisenos));
    ui->listView->show();
    ui->label_Total->setText(QString("%1").arg(ui->listView->model()->rowCount()+1));

    QFileSystemModel *modelCortes = new QFileSystemModel;
    modelCortes->setRootPath(rutaCortes);
    ui->listCorte->setModel(modelCortes);
    ui->listCorte->setRootIndex(modelCortes->index(rutaCortes));
    ui->listCorte->show();
    ui->label_Total_Corte->setText(QString("%1").arg(ui->listCorte->SelectColumns+1));

}

cargarPrograma::~cargarPrograma()
{
    delete ui;
}

void cargarPrograma::on_actionNuevo_triggered()
{
    guardarArchivo *guardar = new guardarArchivo;
    guardar->show();
    cargarPrograma::on_actionEditar_triggered();
}

void cargarPrograma::on_actionEditar_triggered()
{
    if(!archivoLista.isNull()){
        moduloProgramacion *moduloP = new moduloProgramacion;
        moduloP->rutaArchivo = fileName;
        moduloP->CargarArchivo();
        moduloP->showFullScreen();
    }else{
        QMessageBox msgBox;
        msgBox.move(280,110);
        msgBox.setWindowTitle("MENSAJE");
        msgBox.setText("SE DEBE SELECCIONAR UN ARCHIVO");
        msgBox.exec();
    }

}

void cargarPrograma::on_actionSalir_triggered()
{
    this->close();
}

void cargarPrograma::on_actionCopiar_triggered()
{
    if(!archivoLista.isNull()){
        copiarArchivo *copiar = new copiarArchivo;
        copiar->setRuta(fileName);
        copiar->show();
    }else{
        QMessageBox msgBox;
        msgBox.move(280,110);
        msgBox.setWindowTitle("MENSAJE");
        msgBox.setText("SE DEBE SELECCIONAR UN ARCHIVO");
        msgBox.exec();
    }
}

void cargarPrograma::on_actionEliminar_triggered()
{
    QMessageBox msgBox;
    if(!archivoLista.isNull()){
        QFile file(fileName);
        msgBox.move(280,110);
        msgBox.setWindowTitle("MENSAJE");
        msgBox.setText("Desea eliminar el Archivo " +fileName+ " ?");
        msgBox.setStandardButtons(QMessageBox::Yes| QMessageBox::No);

        if (msgBox.exec() == QMessageBox::Yes) {
            if(!file.remove()){
                msgBox.move(280,110);
                msgBox.setWindowTitle("MENSAJE");
                msgBox.setText("ERROR AL ELIMINAR EL ARCHIVO");
                msgBox.exec();
            }
        }
    }else{
        QMessageBox msgBox;
        msgBox.move(280,110);
        msgBox.setWindowTitle("MENSAJE");
        msgBox.setText("SE DEBE SELECCIONAR UN ARCHIVO");
        msgBox.exec();
    }
}

void cargarPrograma::mostrarArchivo(QString ruta){
    ui->textEdit->clear();
    fileName = ruta + archivoLista;

    if ( fileName.isEmpty() )
      return;

    QFile file( fileName );
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       return;

    int cont = 0;
    QTextStream in( &file );
    QString line;
    while (!in.atEnd()) {
      if(cont == 0){
        in.readLine();
      }else{
          if ((cont % 2) == 0) {
               line = "Linea " + QString::number(cont) + " >> " + in.readLine();
               ui->textEdit->append( line );
          }else{
               line = "Linea " + QString::number(cont) + " << " + in.readLine();
               ui->textEdit->append( line );
          }
      }
      cont++;
    }
}

void cargarPrograma::on_listView_clicked(const QModelIndex &index)
{
    ui->listCorte->clearSelection();
    if(ui->listView->isActiveWindow() || ui->listView->isTopLevel()){
        archivoLista = ui->listView->model()->data(index).toString();
        mostrarArchivo(rutaDisenos);
    }
}
void cargarPrograma::on_listCorte_clicked(const QModelIndex &index)
{
    ui->listView->clearSelection();
    if(ui->listCorte->isActiveWindow() || ui->listCorte->isTopLevel()){
        archivoLista = ui->listCorte->model()->data(index).toString();
        mostrarArchivo(rutaCortes);
    }
}

void cargarPrograma::on_pushButton_clicked()
{
    this->hide();
    emit archivoChanged(archivoLista);
}


