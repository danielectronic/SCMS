#include "test.h"
#include "ui_test.h"
#include "threadsensores.h"

Test::Test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Test)
{
    ui->setupUi(this);
}

Test::~Test()
{
    delete ui;
}

void Test::on_GUI1_clicked(bool checked)
{
    if (checked){
        digitalWrite(9,1);
    }else{
        digitalWrite(9,0);
    }
}

void Test::on_GUI2_clicked(bool checked)
{
    if (checked){
        digitalWrite(7,1);
    }else{
        digitalWrite(7,0);
    }
}

void Test::on_GUI3_clicked(bool checked)
{
    if (checked){
        digitalWrite(1,1);
    }else{
        digitalWrite(1,0);
    }
}

void Test::on_GUI4_clicked(bool checked)
{
    if (checked){
        digitalWrite(2,1);
    }else{
        digitalWrite(2,0);
    }
}

void Test::on_DEL_clicked(bool checked)
{
    if (checked){
        digitalWrite(0,1);
    }else{
        digitalWrite(0,0);
    }
}

void Test::on_MED_DEL_clicked(bool checked)
{
    if (checked){
        digitalWrite(3,1);
    }else{
        digitalWrite(3,0);
    }
}

void Test::on_TRA_clicked(bool checked)
{
    if (checked){
        digitalWrite(4,1);
    }else{
        digitalWrite(4,0);
    }
}

void Test::on_MED_TRA_clicked(bool checked)
{
    if (checked){
        digitalWrite(5,1);
    }else{
        digitalWrite(5,0);
    }
}

void Test::on_RON_DEL_IZQ_clicked(bool checked)
{
    if (checked){
        digitalWrite(10,1);
    }else{
        digitalWrite(10,0);
    }
}

void Test::on_RON_DEL_DER_clicked(bool checked)
{
    if (checked){
        digitalWrite(12,1);
    }else{
        digitalWrite(12,0);
    }
}

void Test::on_RON_TRA_IZQ_clicked(bool checked)
{
    if (checked){
        digitalWrite(11,1);
    }else{
        digitalWrite(11,0);
    }
}

void Test::on_RON_TRA_DER_clicked(bool checked)
{
    if (checked){
        digitalWrite(6,1);
    }else{
        digitalWrite(6,0);
    }
}

void Test::on_pushButton_clicked()
{
    this->close();
}

void Test::on_comboBox_activated(int index)
{
    switch (index) {
    case 1:
        digitalWrite(8,0);
        digitalWrite(15,0);
        digitalWrite(16,0);
        break;
    case 2:
        digitalWrite(8,1);
        digitalWrite(15,0);
        digitalWrite(16,0);
        break;
    case 3:
        digitalWrite(8,1);
        digitalWrite(15,1);
        digitalWrite(16,0);
        break;
    case 4:
        digitalWrite(8,0);
        digitalWrite(15,1);
        digitalWrite(16,0);
        break;
    case 5:
        digitalWrite(8,0);
        digitalWrite(15,1);
        digitalWrite(16,1);
        break;
    case 6:
        digitalWrite(8,1);
        digitalWrite(15,1);
        digitalWrite(16,1);
        break;
    case 7:
        digitalWrite(8,0);
        digitalWrite(15,1);
        digitalWrite(16,1);
        break;
    default:
        digitalWrite(8,0);
        digitalWrite(15,0);
        digitalWrite(16,0);
        break;
    }
}
