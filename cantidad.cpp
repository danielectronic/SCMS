#include "cantidad.h"
#include "ui_cantidad.h"

cantidad::cantidad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cantidad)
{
    ui->setupUi(this);
    cantidadDefinida = 0;
    this->move(280,110);
}

cantidad::~cantidad()
{
    delete ui;
}

void cantidad::on_pushButton_clicked()
{
    this->hide();
    nuevaCantidad = ui->spinBox->text().toInt();
    emit cantidadChanged(nuevaCantidad);
}

void cantidad::on_pushButton_2_clicked()
{
    this->close();
}

void cantidad::definirCantidad(int valorCantidad, int valorProg, QString archivo){
    this->NombreArchivo = archivo;
    ui->spinBox->setValue(valorProg);
    ui->label_cantidad->setText(QString::number(valorCantidad));
}
