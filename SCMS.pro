#-------------------------------------------------
#
# Project created by QtCreator 2014-10-02T16:30:52
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SCMS
TEMPLATE = app


SOURCES += main.cpp\
        pantallaprincipal.cpp \
    cantidad.cpp \
    cargarprograma.cpp \
    modificarciclos.cpp \
    copiararchivo.cpp \
    guardararchivo.cpp \
    ingreso.cpp \
    moduloprogramacion.cpp \
    threadsensores.cpp \
    mantenimiento.cpp \
    test.cpp

HEADERS  += pantallaprincipal.h \
    cantidad.h \
    cargarprograma.h \
    modificarciclos.h \
    copiararchivo.h \
    guardararchivo.h \
    ingreso.h \
    moduloprogramacion.h \
    threadsensores.h \
    mantenimiento.h \
    test.h

FORMS    += pantallaprincipal.ui \
    moduloprogramacion2.ui \
    cantidad.ui \
    cargarprograma.ui \
    modificarciclos.ui \
    copiararchivo.ui \
    guardararchivo.ui \
    ingreso.ui \
    moduloprogramacion.ui \
    mantenimiento.ui \
    test.ui

LIBS +=-L/usr/local/lib -lwiringPi

# So wiringPi include files can be found during compile
INCLUDEPATH    += C:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/local/include -lwiringPi

# To link the wiringPi library when making the executable
#LIBS += C:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/local/lib -lwiringPi

RESOURCES += \
    ../../IMAGENES/Imagenes.qrc
