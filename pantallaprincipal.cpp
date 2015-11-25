#include "pantallaprincipal.h"
#include "ui_pantallaprincipal.h"

pantallaPrincipal::pantallaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pantallaPrincipal)
{
    ui->setupUi(this);

    ingreso conn;
    cantidadActual = 0;
    cantidadProg = 0;
    // rutaProgramas = "F:/Universidad/PROYECTOS/SCOMAR/PROGRAMAS/";
    rutaProgramas = "/home/pi/Desktop/PRUEBAS/PROGRAMAS/DISENOS/";
    sensorDer = 0;
    sensorIzq = 0;
    error = 0;
    contLineas = 0;
    contaCiclos = 0;

    wiringPiSetup();
    configGPIO();
    definirObjetos();

   // wiringPiISR(29 ,INT_EDGE_FALLING,pantallaPrincipal::leerPrograma("IZQ"));
   // wiringPiISR(25 ,INT_EDGE_FALLING,pantallaPrincipal::leerPrograma("DER"));

    //connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(leerPrograma()));
    //connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(leerPrograma()));
    conn.connOpen();

    int cantidadRea = 0;
    QSqlQuery qry;
    qry.prepare("SELECT NOMBRE_PROGRAMA, CANTIDAD_PROGRAMADA, CANTIDAD_REALIZADA FROM PROGRAMA_CARGADO");
    if(!qry.exec() )
      qDebug() << qry.lastError();
    else
        while(qry.next()){
            nombrePrograma = qry.value(0).toString();
            cantidadProg = qry.value(1).toInt();
            cantidadRea = qry.value(2).toInt();
        }


    if(cantidadRea < cantidadProg){
        msgBox.move(280,110);
        msgBox.setWindowTitle("MENSAJE");
        msgBox.setText("Desea continuar con la programacion?");
        msgBox.setStandardButtons(QMessageBox::Yes| QMessageBox::No);

        if (msgBox.exec() == QMessageBox::Yes) {
            this->VerPrograma(nombrePrograma);
            ui->cantidadprogEdit->setText(QString::number(cantidadProg));
            ui->cantidadresEdit->setText(QString::number(cantidadActual));
            //lecturaSensores();
        }else{
            this->VerPrograma("");
        }
    }else{
       this->VerPrograma("");
    }
}

pantallaPrincipal::~pantallaPrincipal()
{
    delete ui;
}

void pantallaPrincipal::abrirCargarPrograma(){

}

void pantallaPrincipal::VerPrograma(QString archivo){
    ui->programaEdit->clear();
    NombreArchivo = rutaProgramas + archivo;
    strList.clear();

    QFile file( NombreArchivo );

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       return;

    QTextStream in( &file );

    while (!in.atEnd()) {
        strList << in.readLine();
    }
    strList.removeFirst();

    ui->programaEdit->setText(archivo);
    ui->lineasEdit->clear();
    contLineas = 0;
    cantidadActual = 0;
    if(archivo != ""){
        lecturaSensores();
    }

}

void pantallaPrincipal::leerPrograma(QString Sen){
    QString line;
    //qDebug() << "Sensor activo: " << Sen;
    error = 0;


    if(Sen == "DER"){
    //if (sender()->objectName() == "pushButton_2"){
        if(sensorIzq == 0 && contLineas == 0){
            sensorDer = 1 ;
            rowData = strList.at(contLineas).split(";");
            ui->cicloProgLabel->setText(QString::number(rowData[6].toInt()));
            ui->cicloReaLabel->setText("0");
        }else if(sensorIzq == 1){
            sensorDer = 1;
            sensorIzq = 0;
        }else if (sensorDer == 1 && sensorIzq == 0){
            error = 1;
            if(msgBox.isHidden()){
                msgBox.setWindowTitle(":: MENSAJE ::");
                msgBox.setText("DOBLE LECTURA DE SENSOR DERECHO");
                msgBox.exec();
            }
        }
    }
    if(Sen == "IZQ"){
    //if(sender()->objectName() == "pushButton_8"){
        if(sensorDer == 1){
            sensorIzq = 1 ;
            sensorDer = 0 ;
        }else if(sensorIzq == 1 && sensorDer == 0){
            error = 1;
            if(msgBox.isHidden()){
                msgBox.setWindowTitle(":: MENSAJE ::");
                msgBox.setText("DOBLE LECTURA DE SENSOR IZQUIERDO");
                msgBox.exec();
            }
        }
    }

 /*
    if(Sen == "IZQ"){
    //if (sender()->objectName() == "pushButton_2"){
        if(sensorIzq == 0 && contLineas == 0){
            sensorDer = 1 ;
            rowData = strList.at(contLineas).split(";");
            ui->cicloProgLabel->setText(QString::number(rowData[6].toInt()));
            ui->cicloReaLabel->setText("0");
        }else if(sensorIzq == 1){
            sensorDer = 1;
            sensorIzq = 0;
        }else{
            error = 1;
            QMessageBox msgBox;
            msgBox.setWindowTitle(":: MENSAJE ::");
            msgBox.setText("DOBLE LECTURA DE SENSOR DERECHO");
            msgBox.exec();
        }
    }
    if(Sen == "DER"){
    //if(sender()->objectName() == "pushButton_8"){
        if(sensorDer == 1){
            sensorIzq = 1 ;
            sensorDer = 0 ;
        }else{
            error = 1;
            QMessageBox msgBox;
            msgBox.setWindowTitle(":: MENSAJE ::");
            msgBox.setText("DOBLE LECTURA DE SENSOR IZQUIERDO");
            msgBox.exec();
        }
    }

*/
    if(ui->programaEdit->text() != ""){
        if(cantidadProg > 0){
            if(((sensorDer == 1 || sensorIzq == 1) && error == 0)){
                if (cantidadActual < cantidadProg){
                    if (sensorDer == 1) {
                         if(rowData[6].toInt() == contaCiclos){
                             contLineas++;
                             rowData = strList.at(contLineas).split(";");
                             ui->cicloProgLabel->setText(QString::number(rowData[6].toInt()));
                             contaCiclos = 0;
                             ui->cicloReaLabel->setText(QString::number(contaCiclos));
                             line = "Linea " + QString::number(contLineas+1) + " << " + strList[contLineas];
                             definirSalidas(strList[contLineas], "<<");
                             ui->lineasEdit->setText(line);
                         }else{
                             line = "Linea " + QString::number(contLineas+1) + " << " + strList[contLineas];
                             definirSalidas(strList[contLineas], "<<");
                             ui->lineasEdit->setText(line);
                         }
                    }
                    if(sensorIzq == 1){
                        contaCiclos++;
                        if(rowData[6].toInt() == contaCiclos){
                            contLineas++;
                            line = "Linea " + QString::number(contLineas+1) + " >> " + strList[contLineas];
                            definirSalidas(strList[contLineas], ">>");
                            ui->lineasEdit->setText(line);
                            ui->cicloReaLabel->setText(QString::number(contaCiclos));
                        }else{
                            contLineas++;
                            ui->cicloReaLabel->setText(QString::number(contaCiclos));
                            line = "Linea " + QString::number(contLineas+1) + " >> " + strList[contLineas];
                            definirSalidas(strList[contLineas], ">>");
                            ui->lineasEdit->setText(line);
                            contLineas--;
                        }
                    }

                    if(contLineas == strList.count() - 1){
                        contLineas = 0;
                        sensorIzq = 0;
                        contaCiclos = 0;
                        cantidadActual++;
                        actualizarCantidadFaltante(cantidadActual);
                    }

                    ui->cantidadresEdit->setText(QString::number(cantidadActual));
                }else{
                    msgBox.setWindowTitle(":: MENSAJE ::");
                    msgBox.setText("PRODUCCION TERMINADA");
                    msgBox.exec();
                    cantidadActual = 0;
                    cantidadProg = 0;
                    Sensores->stop();
                    ui->cantidadprogEdit->setText(QString::number(cantidadProg));
                    ui->cantidadresEdit->setText(QString::number(cantidadActual));
                    //ui->programaEdit->clear();
                }

            }else{
                qDebug() << "ERROR DE DOBLE LECTURA DE SENSOR";
                error = 0;
                return;
            }
        }else{
            msgBox.setWindowTitle(":: MENSAJE ::");
            msgBox.setText("NO HAY UNA CANTIDAD DEFINIDA");
            msgBox.exec();
        }
    }else{
        msgBox.setWindowTitle(":: MENSAJE ::");
        msgBox.setText("NO HAY UN PROGRAMA CARGADO");
        msgBox.exec();
    }

}


void pantallaPrincipal::on_pushButton_9_clicked()
{
    //cantidad *cant = new cantidad;
    cant->definirCantidad(cantidadActual, cantidadProg, ui->programaEdit->text());
    //connect(cant,SIGNAL(cantidadChanged(int)),this,SLOT(progCantidad(int)));
    cant->show();

    ingreso conn;
    conn.connOpen();
    QString qry = "UPDATE PROGRAMA_CARGADO SET CANTIDAD_PROGRAMADA = ? WHERE NOMBRE_PROGRAMA = ?";
    QSqlQuery query(qry);
    query.addBindValue(nombrePrograma);
    query.addBindValue(cant->nuevaCantidad);
    query.exec();
    conn.connClose();
}

void pantallaPrincipal::progCantidad(int valor){
    cantidadProg = valor;
    ui->cantidadprogEdit->setText(QString::number(cantidadProg));
    //ui->cantidadresEdit->setText(QString::number(cantidadActual));
}

void pantallaPrincipal::on_pushButton_clicked()
{
    if(ui->programaEdit->text() != ""){
        //modificarCiclos *ciclo = new modificarCiclos;
        ciclo->cargarCiclos(strList);
        //connect(ciclo,SIGNAL(ciclosChanged(QStringList)),this,SLOT(progCiclos(QStringList)));
        ciclo->show();
    }else{
        msgBox.setWindowTitle("MENSAJE");
        msgBox.setText("NO HAY UN PROGRAMA CARGADO");
        msgBox.exec();
    }
}

void pantallaPrincipal::configGPIO(){

    //CONFIGURACION PINES DE ENTRADA
    pinMode(29,INPUT); //SENSOR IZQUIERDO
    pinMode(25,INPUT); //SENSOR DERECHO

    //CONFIGURACION PINES DE SALIDA

    pinMode(21,OUTPUT); //LUZ

    pinMode(8,OUTPUT); //VEL1
    pinMode(15,OUTPUT); //VEL2
    pinMode(16,OUTPUT); //VEL3

    pinMode(9,OUTPUT); //GUI1
    pinMode(7,OUTPUT); //GUI2
    pinMode(1,OUTPUT); //GUI3
    pinMode(2,OUTPUT); //GUI4

    pinMode(0,OUTPUT); //llaDel
    pinMode(3,OUTPUT); //llaDelMed
    pinMode(4,OUTPUT); //llaTra
    pinMode(5,OUTPUT); //llaTraMed

    pinMode(12,OUTPUT); //ronDelDer
    pinMode(6,OUTPUT); //ronTraDer
    pinMode(10,OUTPUT); //ronDelIzq
    pinMode(11,OUTPUT); //ronTraIzq

}

void pantallaPrincipal::definirSalidas(QString data, QString sentido){
    qDebug() << data;
    salidas = data.split(";");

    //VELOCIDAD
    switch (salidas[0].toInt()) {
    case 1:
        vel1 = 0;
        vel2 = 0;
        vel3 = 0;
        break;
    case 2:
        vel1 = 1;
        vel2 = 0;
        vel3 = 0;
        break;
    case 3:
        vel1 = 1;
        vel2 = 1;
        vel3 = 0;
        break;
    case 4:
        vel1 = 0;
        vel2 = 1;
        vel3 = 0;
        break;
    case 5:
        vel1 = 0;
        vel2 = 1;
        vel3 = 1;
        break;
    case 6:
        vel1 = 1;
        vel2 = 1;
        vel3 = 1;
        break;
    case 7:
        vel1 = 0;
        vel2 = 0;
        vel3 = 1;
        break;
    default:
        vel1 = 0;
        vel2 = 0;
        vel3 = 0;
        break;
    }
    //GUIA HILOS
    switch (salidas[1].toInt()) {
    case 1:
        gui1 = 1;
        gui2 = 0;
        gui3 = 0;
        gui4 = 0;
        break;
    case 2:
        gui1 = 0;
        gui2 = 1;
        gui3 = 0;
        gui4 = 0;
        break;
    case 3:
        gui1 = 0;
        gui2 = 0;
        gui3 = 1;
        gui4 = 0;
        break;
    case 4:
        gui1 = 0;
        gui2 = 0;
        gui3 = 0;
        gui4 = 1;
        break;
    default:
        gui1 = 0;
        gui2 = 0;
        gui3 = 0;
        gui4 = 0;
        break;
    }

    //LLAVE DELANTERA
    switch (salidas[2].toInt()) {
    case 0:
        llaDel = 0;
        llaDelMed = 0;
        break;
    case 1:
        llaDel = 1;
        llaDelMed = 1;
        break;
    case 6:
        llaDel = 0;
        llaDelMed = 1;
        break;
    default:
        llaDel = 0;
        llaDelMed = 0;
        break;
    }

    //LLAVE TRASERA
    switch (salidas[3].toInt()) {
    case 0:
        llaTra = 0;
        llaTraMed = 0;
        break;
    case 1:
        llaTra = 1;
        llaTraMed = 1;
        break;
    case 6:
        llaTra = 0;
        llaTraMed = 1;
        break;
    default:
        llaTra = 0;
        llaTraMed = 0;
        break;
    }
if (sentido == "<<"){
    //RONDO DELANTERO DERECHO
    switch (salidas[4].toInt()) {
    case 0:
        ronDelDer = 0;
        break;
    case 1:
        ronDelDer = 1;
        break;
    default:
        ronDelDer = 0;
        break;
    }

    //RONDO TRASERO DERECHO
    switch (salidas[5].toInt()) {
    case 0:
        ronTraDer = 0;
        break;
    case 1:
        ronTraDer = 1;
        break;
    default:
        ronTraDer = 0;
        break;
    }
}else{
    //RONDO DERECHO
    switch (salidas[4].toInt()) {
    case 0:
        ronDelIzq = 0;
        break;
    case 1:
        ronDelIzq = 1;
        break;
    default:
        ronDelIzq = 0;
        break;
    }

    switch (salidas[5].toInt()) {
    case 0:
        ronTraIzq = 0;
        break;
    case 1:
        ronTraIzq = 1;
        break;
    default:
        ronTraIzq = 0;
        break;
    }

}
    digitalWrite(8,vel1);
    digitalWrite(15,vel2);
    digitalWrite(16,vel3);

    digitalWrite(9,gui1);
    digitalWrite(7,gui2);
    digitalWrite(1,gui3);
    digitalWrite(2,gui4);

    digitalWrite(0,llaDel);
    digitalWrite(3,llaDelMed);
    digitalWrite(4,llaTra);
    digitalWrite(5,llaTraMed);


    if (sentido == "<<"){
        digitalWrite(12,ronDelDer);
        digitalWrite(6,ronTraDer);
        digitalWrite(10,0);
        digitalWrite(11,0);
    }else{
        digitalWrite(10,ronDelIzq);
        digitalWrite(11,ronTraIzq);
        digitalWrite(12,0);
        digitalWrite(6,0);
    }
}


void pantallaPrincipal::on_pushButton_10_clicked(bool checked)
{
    if (checked){
        digitalWrite(21,1);
    }else{
        digitalWrite(21,0);
    }
}

void pantallaPrincipal::on_pushButton_11_clicked()
{
    msgBox.move(280,110);
    msgBox.setWindowTitle("MENSAJE");
    msgBox.setText("Realmente Desea Apagar el Sistema?");
    msgBox.setStandardButtons(QMessageBox::Yes| QMessageBox::No);

    if (msgBox.exec() == QMessageBox::Yes) {
        //system("sudo poweroff");
        system("sudo halt");
    }
}
void pantallaPrincipal::on_pushButton_3_clicked()
{
    Mantenimiento *m = new Mantenimiento;
    m->showFullScreen();
}

void pantallaPrincipal::lecturaSensores(){
    //if(Sensores->isFinished()){
        //Sensores = new ThreadSensores(this);
        //connect(Sensores,SIGNAL(sensorChanged(QString)),this,SLOT(leerPrograma(QString)));
    if(!Sensores->isRunning())
    {
        Sensores->start();
    }
    //}
}

void pantallaPrincipal::on_pushButton_7_clicked()
{
    //cargarPrograma *CargarPrograma = new cargarPrograma;
    //connect(CargarPrograma,SIGNAL(archivoChanged(QString)),this,SLOT(VerPrograma(QString)));
    CargarPrograma->showFullScreen();

    ingreso conn;
    QString qry;
    conn.connOpen();

    qry = "DELETE FROM PROGRAMA_CARGADO";
    QSqlQuery h(qry);
    h.exec();

    qry = "INSERT INTO PROGRAMA_CARGADO (NOMBRE_PROGRAMA, PERFIL_USUARIO, CANTIDAD_PROGRAMADA, CANTIDAD_FALTANTE) VALUES (?,?,?,?)";
    QSqlQuery query(qry);
    query.addBindValue(CargarPrograma->archivoLista);
    query.addBindValue("ADM");
    query.addBindValue(0);
    query.addBindValue(0);
    query.exec();
    conn.connClose();
}

void pantallaPrincipal::actualizarCantidadFaltante(int cantidadFaltante){
    ingreso conn;
    QString qry;
    conn.connOpen();

    qry = "UPDATE PROGRAMA_CARGADO SET CANTIDAD_REALIZADA = ?)";
    QSqlQuery query(qry);
    query.addBindValue(cantidadFaltante);
    query.exec();
    conn.connClose();
}

void pantallaPrincipal::definirObjetos(){
    //OBJETOS
    cant = new cantidad;
    ciclo = new modificarCiclos;
    Sensores = new ThreadSensores(this);
    CargarPrograma = new cargarPrograma;

    //CONEXIONES
    connect(cant,SIGNAL(cantidadChanged(int)),this,SLOT(progCantidad(int)));
    connect(ciclo,SIGNAL(ciclosChanged(QStringList)),this,SLOT(progCiclos(QStringList)));
    connect(Sensores,SIGNAL(sensorChanged(QString)),this,SLOT(leerPrograma(QString)));
    connect(CargarPrograma,SIGNAL(archivoChanged(QString)),this,SLOT(VerPrograma(QString)));
}
