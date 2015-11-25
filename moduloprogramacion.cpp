#include "moduloprogramacion.h"
#include "ui_moduloprogramacion.h"

moduloProgramacion::moduloProgramacion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::moduloProgramacion)
{
    ui->setupUi(this);
}

moduloProgramacion::~moduloProgramacion()
{
    delete ui;
}

void moduloProgramacion::CargarArchivo(){

    QString data;
    QFile importedCSV(rutaArchivo);
    QStringList rowOfData;
    QStringList rowData;
    data.clear();
    rowOfData.clear();
    rowData.clear();

    if (importedCSV.open(QFile::ReadOnly))
    {
        data = importedCSV.readAll();
        rowOfData = data.split("\n");           //Value on each row
        importedCSV.close();
    }

    for (int x = 1; x < rowOfData.size()-1; x++)  //rowOfData.size() gives the number of row
    {
        rowData = rowOfData.at(x).split(";");   //Number of collumn

        for (int y = 0; y < rowData.size(); y++)
        {
            ui->tableWidget->setRowCount(x);
            ui->tableWidget->setItem(x-1, y, new QTableWidgetItem(rowData[y]));

        }
    }
    ui->statusBar->showMessage(tr("File successfully loaded."), 3000);
}

void moduloProgramacion::on_actionGuardar_Programa_triggered()
{
    QFile file(rutaArchivo);

    if (file.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream data(&file);
        QStringList strList;
        for( int c = 0; c < ui->tableWidget->columnCount(); ++c )
        {
            strList << ui->tableWidget->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString();
        }

        data << strList.join(";") << "\n";
        for( int r = 0; r < ui->tableWidget->rowCount(); ++r )
        {
            strList.clear();
            for( int c = 0; c < ui->tableWidget->columnCount(); ++c )
            {   QTableWidgetItem* item = ui->tableWidget->item(r,c);        //Load items
                if (!item || item->text().isEmpty())                        //Test if there is something at item(r,c)
                {
                    ui->tableWidget->setItem(r,c,new QTableWidgetItem("0"));//IF there is nothing write 0
                }
                strList << ui->tableWidget->item( r, c )->text();

            }
            data << strList.join( ";" )+"\n";
        }
        ui->statusBar->showMessage(tr("Archivo Guardado Correctamente"), 3000);
        file.close();
    }
}

void moduloProgramacion::on_actionInsertar_Linea_triggered()
{
    int currentRow;
    currentRow =  ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(currentRow + 1);

    ui->tableWidget->setItem(currentRow, 0, new QTableWidgetItem(ui->spinBox->text()));
    ui->tableWidget->setItem(currentRow, 1, new QTableWidgetItem(ui->spinBox_3->text()));
    ui->tableWidget->setItem(currentRow, 2, new QTableWidgetItem(ui->spinBox_5->text()));
    ui->tableWidget->setItem(currentRow, 3, new QTableWidgetItem(ui->spinBox_7->text()));
    ui->tableWidget->setItem(currentRow, 4, new QTableWidgetItem(ui->spinBox_9->text()));
    ui->tableWidget->setItem(currentRow, 5, new QTableWidgetItem(ui->spinBox_11->text()));
    //ui->tableWidget->setItem(currentRow, 6, new QTableWidgetItem(ui->spinBox_13->text()));
    //ui->tableWidget->setItem(currentRow, 7, new QTableWidgetItem(ui->spinBox_15->text()));
    ui->tableWidget->setItem(currentRow, 6, new QTableWidgetItem(ui->spinBox_17->text()));

    currentRow =  ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(currentRow + 1);

    ui->tableWidget->setItem(currentRow, 0, new QTableWidgetItem(ui->spinBox_2->text()));
    ui->tableWidget->setItem(currentRow, 1, new QTableWidgetItem(ui->spinBox_3->text()));
    ui->tableWidget->setItem(currentRow, 2, new QTableWidgetItem(ui->spinBox_6->text()));
    ui->tableWidget->setItem(currentRow, 3, new QTableWidgetItem(ui->spinBox_8->text()));
    ui->tableWidget->setItem(currentRow, 4, new QTableWidgetItem(ui->spinBox_10->text()));
    ui->tableWidget->setItem(currentRow, 5, new QTableWidgetItem(ui->spinBox_12->text()));
    //ui->tableWidget->setItem(currentRow, 6, new QTableWidgetItem(ui->spinBox_14->text()));
    //ui->tableWidget->setItem(currentRow, 7, new QTableWidgetItem(ui->spinBox_16->text()));
    ui->tableWidget->setItem(currentRow, 6, new QTableWidgetItem("X"));
}

void moduloProgramacion::EditarCelda(){
    ui->tableWidget->removeCellWidget(fila,columna);

    fila = ui->tableWidget->currentItem()->row();
    columna = ui->tableWidget->currentItem()->column();

    QSpinBox *widget = new QSpinBox();
    widget->setValue(ui->tableWidget->item(fila,columna)->text().toInt());
    ui->tableWidget->setCellWidget(fila, columna, widget);

    QObject::connect(widget, SIGNAL(valueChanged(int)),this, SLOT(spinBoxChange(int)));
}

void moduloProgramacion::spinBoxChange(int value){
    ui->tableWidget->item(fila,columna)->setText(QString::number(value));
}

void moduloProgramacion::on_actionSalir_triggered()
{
    this->close();
}

void moduloProgramacion::on_actionEliminar_Linea_triggered()
{
    if(ui->tableWidget->isItemSelected(ui->tableWidget->currentItem())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("MENSAJE");
        msgBox.setText("Realmente desea Eliminar las Lineas?");
        msgBox.setStandardButtons(QMessageBox::Yes| QMessageBox::No);

        if (msgBox.exec() == QMessageBox::Yes) {
            ui->tableWidget->removeRow(ui->tableWidget->currentRow());
            ui->tableWidget->removeRow(ui->tableWidget->currentRow()+1);
        }
    }else{
        QMessageBox msgBox;
        msgBox.setWindowTitle("MENSAJE");
        msgBox.setText("SE DEBE SELECCIONAR UNA LINEA");
        msgBox.exec();
    }
}

void moduloProgramacion::on_actionInsertar_Corte_triggered()
{

}
