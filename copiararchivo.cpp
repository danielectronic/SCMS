#include "copiararchivo.h"
#include "ui_copiararchivo.h"

copiarArchivo::copiarArchivo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::copiarArchivo)
{
    ui->setupUi(this);
    this->move(280,110);
}

copiarArchivo::~copiarArchivo()
{
    delete ui;
}

void copiarArchivo::setRuta(QString ruta){
    rutaOrigen = ruta;
}

void copiarArchivo::on_buttonBox_accepted()
{
    QFile myFile (rutaOrigen);
    QString nombreArchivo = ui->lineEdit->text();

    while(!rutaOrigen.endsWith("/")){
        rutaOrigen.remove(rutaOrigen.length()-1,1);
    }

    if (!myFile.copy(rutaOrigen + nombreArchivo + ".csv")){
    //if (!myFile.copy("F:/Universidad/PROYECTOS/SCOMAR/PROGRAMAS/"+ nombreArchivo + ".csv")){
        QMessageBox msgBox;
        msgBox.setWindowTitle("MENSAJE");
        msgBox.setText("ERROR COPIANDO ARCHIVO");
        msgBox.exec();
        this->close();
    }else{
        this->close();
    }
}

void copiarArchivo::on_buttonBox_rejected()
{
    this->close();
}
