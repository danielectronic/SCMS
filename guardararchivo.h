#ifndef GUARDARARCHIVO_H
#define GUARDARARCHIVO_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>

namespace Ui {
class guardarArchivo;
}

class guardarArchivo : public QWidget
{
    Q_OBJECT

public:
    explicit guardarArchivo(QWidget *parent = 0);
    ~guardarArchivo();

private slots:
    void on_buttonBox_accepted();

    void on_checkBox_clicked(bool checked);

    void on_checkBox_2_clicked(bool checked);

    void on_buttonBox_rejected();

private:
    Ui::guardarArchivo *ui;
};

#endif // GUARDARARCHIVO_H
