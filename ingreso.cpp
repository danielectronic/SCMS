#include "ingreso.h"
#include "ui_ingreso.h"

ingreso::ingreso(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ingreso)
{
    ui->setupUi(this);
}

ingreso::~ingreso()
{
    delete ui;
}

void ingreso::on_pushButton_clicked()
{
    QString usuario,contrasena;
    usuario=ui->lineEdit->text();
    contrasena=ui->lineEdit_2->text();
    int cont = 1;
/*
    if(!connOpen()){
        qDebug()<<"ERROR CONECTANDO A BASE DE DATOS";
        return;
    }

    connOpen(); //ABRE CONEXION CON LA BASE DE DATOS
    QSqlQuery qry;
    qry.prepare("SELECT * FROM PERSONAS WHERE USUARIO='"+usuario+"' AND CONTRASENA='"+contrasena+"'");

    if(qry.exec()){

        int cont=0;
        while(qry.next()){
            cont++;
        }
*/
        if(cont==1){
            //connClose();
            this->hide();
            pantallaPrincipal *pantallaprincipal = new pantallaPrincipal;
            pantallaprincipal->showFullScreen();
        }
        if(cont<1){
            QMessageBox msgBox;
            msgBox.setWindowTitle("MENSAJE");
            msgBox.setText("USUARIO Y CONTRASEÑA INCORRECTOS");
            msgBox.exec();
            //connClose();
        }

        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
  // }

}
