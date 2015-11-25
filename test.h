#ifndef TEST_H
#define TEST_H

#include <QWidget>
#include "wiringPi.h"
#include <threadsensores.h>
#include <QThread>

namespace Ui {
class Test;
}

class Test : public QWidget
{
    Q_OBJECT

public:
    explicit Test(QWidget *parent = 0);
    ~Test();

private slots:

    void on_pushButton_clicked();

    void on_comboBox_activated(int index);


    void on_GUI1_clicked(bool checked);

    void on_GUI2_clicked(bool checked);

    void on_GUI3_clicked(bool checked);

    void on_GUI4_clicked(bool checked);

    void on_DEL_clicked(bool checked);

    void on_MED_DEL_clicked(bool checked);

    void on_TRA_clicked(bool checked);

    void on_MED_TRA_clicked(bool checked);

    void on_RON_DEL_IZQ_clicked(bool checked);

    void on_RON_DEL_DER_clicked(bool checked);

    void on_RON_TRA_IZQ_clicked(bool checked);

    void on_RON_TRA_DER_clicked(bool checked);

private:
    Ui::Test *ui;
};

#endif // TEST_H
