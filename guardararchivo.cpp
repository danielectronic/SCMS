#include "guardararchivo.h"
#include "ui_guardararchivo.h"

guardarArchivo::guardarArchivo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::guardarArchivo)
{
    ui->setupUi(this);
    this->move(280,110);
}

guardarArchivo::~guardarArchivo()
{
    delete ui;
}

void guardarArchivo::on_buttonBox_accepted()
{
    QString nombreArchivo = ui->lineEdit->text();
    QString rutaArchivo;
    //QFile file("F:/Universidad/PROYECTOS/SCOMAR/PROGRAMAS/" + nombreArchivo + ".csv");
    if(ui->checkBox->isChecked()){
        rutaArchivo = "DISENOS/";
    }else if(ui->checkBox_2->isChecked()){
        rutaArchivo = "CORTES/";
    }
    QFile file("/home/pi/Desktop/PRUEBAS/PROGRAMAS/"+ rutaArchivo + nombreArchivo + ".csv");

    if(!file.open(QFile::WriteOnly | QFile::Text )){
        QMessageBox msgBox;
         msgBox.setText("ERROR CREANDO EL ARCHIVO");
         msgBox.exec();
    }
    file.close();
    this->close();
}

void guardarArchivo::on_checkBox_clicked(bool checked)
{
    if(checked){
        ui->checkBox_2->setDisabled(true);
    }else{
       ui->checkBox_2->setDisabled(false);
    }
}

void guardarArchivo::on_checkBox_2_clicked(bool checked)
{
    if(checked){
        ui->checkBox->setDisabled(true);
    }else{
        ui->checkBox->setDisabled(false);
    }
}

void guardarArchivo::on_buttonBox_rejected()
{
    this->close();
}
