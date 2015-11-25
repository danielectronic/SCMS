#include "mantenimiento.h"
#include "ui_mantenimiento.h"
#include "pantallaprincipal.h"

Mantenimiento::Mantenimiento(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mantenimiento)
{
    ui->setupUi(this);
    //qt = new ThreadSensores();
}

Mantenimiento::~Mantenimiento()
{
    delete ui;
}

void Mantenimiento::on_pushButton_6_clicked()
{
    Test *t = new Test;
    t->show();
}

void Mantenimiento::on_pushButton_5_clicked()
{
    this->enabledChange(false);
    for (int var = 1; var < 13; ++var) {


        switch (var) {
        case 1:
            for (int var = 0; var < 5; ++var) {
                digitalWrite(9,1); //GUI1
                qt->sleep(200);
                digitalWrite(9,0);
                qt->sleep(200);
            }

            break;
        case 2:
            for (int var = 0; var < 5; ++var) {
                digitalWrite(7,1); //GUI2
                qt->sleep(200);
                digitalWrite(7,0);
                qt->sleep(200);
            }
            break;
        case 3:
            for (int var = 0; var < 5; ++var) {
                digitalWrite(1,1); //GUI3
                qt->sleep(200);
                digitalWrite(1,0);
                qt->sleep(200);
            }
            break;
        case 4:
            for (int var = 0; var < 5; ++var) {
                digitalWrite(2,1); //GUI4
                qt->sleep(200);
                digitalWrite(2,0);
                qt->sleep(200);
            }
            break;
        case 5:
            for (int var = 0; var < 5; ++var) {
                digitalWrite(0,1); //VllaDel
                qt->sleep(200);
                digitalWrite(0,0);
                qt->sleep(200);
            }
            break;
        case 6:
            for (int var = 0; var < 5; ++var) {
                digitalWrite(3,1); //llaDelMed
                qt->sleep(200);
                digitalWrite(3,0);
                qt->sleep(200);
            }
            break;
        case 7:
            for (int var = 0; var < 5; ++var) {
                digitalWrite(4,1); //llaTra
                qt->sleep(200);
                digitalWrite(4,0);
                qt->sleep(200);
            }
            break;
        case 8:
            for (int var = 0; var < 5; ++var) {
                digitalWrite(5,1); //llaTraMed
                qt->sleep(200);
                digitalWrite(5,0);
                qt->sleep(200);
            }
            break;
        case 9:
            for (int var = 0; var < 5; ++var) {
                digitalWrite(12,1); //ronDelDer
                qt->sleep(200);
                digitalWrite(12,0);
                qt->sleep(200);
            }
            break;
        case 10:
            for (int var = 0; var < 5; ++var) {
                digitalWrite(10,1); //ronDelIzq
                qt->sleep(200);
                digitalWrite(10,0);
                qt->sleep(200);
            }
            break;
        case 11:
            for (int var = 0; var < 5; ++var) {
                digitalWrite(6,1); //ronTraDer
                qt->sleep(200);
                digitalWrite(6,0);
                qt->sleep(200);
            }
            break;
        case 12:
            for (int var = 0; var < 5; ++var) {
                digitalWrite(11,1); //ronTraIzq
                qt->sleep(200);
                digitalWrite(11,0);
                qt->sleep(200);
            }
            break;
            /*
        case 13:
            for (int var = 0; var < 5; ++var) {
                digitalWrite(27,1); //VEL1
                qt->sleep(200);
                digitalWrite(27,0); //VEL1
                qt->sleep(200);
            }
            break;
        case 14:
            for (int var = 0; var < 5; ++var) {
                digitalWrite(28,1); //VEL1
                qt->sleep(200);
                digitalWrite(28,0); //VEL1
                qt->sleep(200);
            }
            break;
        case 15:
            for (int var = 0; var < 5; ++var) {
                digitalWrite(29,1); //VEL1
                qt->sleep(200);
                digitalWrite(29,0); //VEL1
                qt->sleep(200);
            }
            break;
            */
        default:
            break;
        }
    }
    this->enabledChange(true);
}

void Mantenimiento::on_pushButton_7_clicked()
{
    this->hide();
}

void Mantenimiento::on_pushButton_clicked()
{
    pantallaPrincipal *p = new pantallaPrincipal();
    p->cambiarContLineas(3);
}
