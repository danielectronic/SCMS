#ifndef CANTIDAD_H
#define CANTIDAD_H

#include <QWidget>

namespace Ui {
class cantidad;
}

class cantidad : public QWidget
{
    Q_OBJECT

public:
    explicit cantidad(QWidget *parent = 0);
    ~cantidad();
    void definirCantidad(int, int, QString archivo);
    int nuevaCantidad;

signals:
    void cantidadChanged(int);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::cantidad *ui;
    int cantidadDefinida;
    QString NombreArchivo;
};

#endif // CANTIDAD_H
