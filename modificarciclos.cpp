#include "modificarciclos.h"
#include "ui_modificarciclos.h"

modificarCiclos::modificarCiclos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::modificarCiclos)
{
    ui->setupUi(this);
    this->move(250,100);
}

modificarCiclos::~modificarCiclos()
{
    delete ui;
}

void modificarCiclos::cargarCiclos(QStringList lista){
    datosLista = lista;
    int x = 0;
    for (int var = 0; var < datosLista.count(); ++var) {
        rowData = datosLista.at(var).split(";");
        data << rowData[6];

        if (data[var] != "X" && data[var] != "1"){
            ui->tableWidget->setRowCount(x+1);
            ui->tableWidget->setItem(x, 0, new QTableWidgetItem(QString::number(var+1)));
            ui->tableWidget->setItem(x, 1, new QTableWidgetItem(data[var]));
            x++;
        }

    }
}

void modificarCiclos::EditarCelda(){
    //ui->tableWidget->removeCellWidget(fila,columna);

    fila = ui->tableWidget->currentItem()->row();
    columna = ui->tableWidget->currentItem()->column();

    QSpinBox *widget = new QSpinBox();
    widget->setValue(ui->tableWidget->item(fila,columna)->text().toInt());
    ui->tableWidget->setCellWidget(fila, columna, widget);

    connect(widget, SIGNAL(valueChanged(int)),this, SLOT(spinBoxChange(int)));
}

void modificarCiclos::spinBoxChange(int value){
    ui->tableWidget->item(fila,columna)->setText(QString::number(value));
}

void modificarCiclos::on_pushButton_clicked()
{
    QString datos;
    for (int var = 0; var < datosLista.count(); ++var) {
        rowData = datosLista.at(var).split(";");

        rowData[6] = ui->tableWidget->item( var, 1 )->text();
        datos = rowData[0] +";"+ rowData[1] +";"+ rowData[2] +";"+ rowData[3] +";"+ rowData[4] +";"+ rowData[5] +";"+ rowData[6];
        datosLista.removeAt(var);
        datosLista.insert(var, datos);
    }
    this->hide();
    emit ciclosChanged(datosLista);
}

void modificarCiclos::on_pushButton_2_clicked()
{
    this->hide();
}
