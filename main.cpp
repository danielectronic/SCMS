#include "ingreso.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ingreso w;
    w.showFullScreen();

    return a.exec();
}
