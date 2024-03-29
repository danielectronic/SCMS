#############################################################################
# Makefile for building: SCMS
# Generated by qmake (2.01a) (Qt 4.8.6) on: vie. 3. oct. 14:05:53 2014
# Project:  SCMS.pro
# Template: app
# Command: c:/SysGCC/Raspberry/bin/qmake.exe -o Makefile SCMS.pro
#############################################################################

####### Compiler, tools and options

CC            = C:/SysGCC/Raspberry/bin/arm-linux-gnueabihf-gcc.exe
CXX           = C:/SysGCC/Raspberry/bin/arm-linux-gnueabihf-g++.exe
DEFINES       = -D_LARGEFILE64_SOURCE -D_LARGEFILE_SOURCE -DQT_SQL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_HAVE_MMX -DQT_HAVE_SSE -DQT_HAVE_MMXEXT -DQT_HAVE_SSE2
CFLAGS        = -pipe -Wno-psabi -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -Wno-psabi -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -Ic:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/arm-linux-gnueabihf -I. -Ic:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/include/qt4/QtCore -Ic:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/include/qt4/QtGui -Ic:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/include/qt4/QtSql -Ic:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/include/qt4 -I. -I.
LINK          = C:/SysGCC/Raspberry/bin/arm-linux-gnueabihf-g++.exe
LFLAGS        = 
LIBS          = $(SUBLIBS)  -LC:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/lib -lQtSql -lQtGui -lQtCore -lpthread 
AR            = C:/SysGCC/Raspberry/bin/arm-linux-gnueabihf-ar.exe cqs
RANLIB        = 
QMAKE         = c:/SysGCC/Raspberry/bin/qmake.exe
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = copy /y
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = xcopy /s /q /y /i
STRIP         = C:/SysGCC/Raspberry/bin/arm-linux-gnueabihf-strip.exe
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = del
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = move
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		pantallaprincipal.cpp moc_pantallaprincipal.cpp \
		qrc_Imagenes.cpp
OBJECTS       = main.o \
		pantallaprincipal.o \
		moc_pantallaprincipal.o \
		qrc_Imagenes.o
DIST          = c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/common/unix.conf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/common/linux.conf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/common/gcc-base.conf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/common/g++-base.conf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/common/g++-unix.conf \
		c:/Qt/4.8.6/mkspecs/qconfig.pri \
		c:/Qt/4.8.6/mkspecs/modules/qt_webkit_version.pri \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/qt_functions.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/qt_config.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/default_pre.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/debug.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/default_post.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/unix/largefile.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/shared.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/warn_on.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/qt.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/unix/thread.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/moc.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/resources.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/uic.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/yacc.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/lex.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		SCMS.pro
QMAKE_TARGET  = SCMS
DESTDIR       = 
TARGET        = SCMS

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_pantallaprincipal.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: SCMS.pro  c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/arm-linux-gnueabihf/qmake.conf c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/common/unix.conf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/common/linux.conf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/common/gcc-base.conf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/common/g++-base.conf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/common/g++-unix.conf \
		c:/Qt/4.8.6/mkspecs/qconfig.pri \
		c:/Qt/4.8.6/mkspecs/modules/qt_webkit_version.pri \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/qt_functions.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/qt_config.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/default_pre.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/debug.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/default_post.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/unix/largefile.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/shared.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/warn_on.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/qt.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/unix/thread.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/moc.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/resources.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/uic.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/yacc.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/lex.prf \
		c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/include_source_dir.prf
	$(QMAKE) -o Makefile SCMS.pro
c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/common/unix.conf:
c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/common/linux.conf:
c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/common/gcc-base.conf:
c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/common/g++-base.conf:
c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/common/g++-unix.conf:
c:/Qt/4.8.6/mkspecs/qconfig.pri:
c:/Qt/4.8.6/mkspecs/modules/qt_webkit_version.pri:
c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/qt_functions.prf:
c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/qt_config.prf:
c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/default_pre.prf:
c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/debug.prf:
c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/default_post.prf:
c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/unix/largefile.prf:
c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/shared.prf:
c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/warn_on.prf:
c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/qt.prf:
c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/unix/thread.prf:
c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/moc.prf:
c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/resources.prf:
c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/uic.prf:
c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/yacc.prf:
c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/lex.prf:
c:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/features/include_source_dir.prf:
qmake:  FORCE
	@$(QMAKE) -o Makefile SCMS.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/SCMS1.0.0 || $(MKDIR) .tmp/SCMS1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/SCMS1.0.0/ && $(COPY_FILE) --parents pantallaprincipal.h .tmp/SCMS1.0.0/ && $(COPY_FILE) --parents ../../IMAGENES/Imagenes.qrc .tmp/SCMS1.0.0/ && $(COPY_FILE) --parents main.cpp pantallaprincipal.cpp .tmp/SCMS1.0.0/ && $(COPY_FILE) --parents pantallaprincipal.ui .tmp/SCMS1.0.0/ && (cd `dirname .tmp/SCMS1.0.0` && $(TAR) SCMS1.0.0.tar SCMS1.0.0 && $(COMPRESS) SCMS1.0.0.tar) && $(MOVE) `dirname .tmp/SCMS1.0.0`/SCMS1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/SCMS1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

C:/Qt/4.8.6/bin/moc.exe:
	(cd $(QTDIR)/src/tools/moc && $(MAKE))

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_pantallaprincipal.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_pantallaprincipal.cpp
moc_pantallaprincipal.cpp: pantallaprincipal.h \
		c:/Qt/4.8.6/bin/moc.exe
	C:/Qt/4.8.6/bin/moc.exe $(DEFINES) $(INCPATH) pantallaprincipal.h -o moc_pantallaprincipal.cpp

compiler_rcc_make_all: qrc_Imagenes.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_Imagenes.cpp
qrc_Imagenes.cpp: ../../IMAGENES/Imagenes.qrc \
		../../IMAGENES/contrasena.png \
		../../IMAGENES/editar.png \
		../../IMAGENES/ON.png \
		../../IMAGENES/abrir.png \
		../../IMAGENES/OFF.png \
		../../IMAGENES/TEJIDOS.jpg \
		../../IMAGENES/nuevo.png \
		../../IMAGENES/CICLOS.png \
		../../IMAGENES/eliminar.png \
		../../IMAGENES/usuario.png \
		../../IMAGENES/ingresar.png \
		../../IMAGENES/insertar.png \
		../../IMAGENES/clone.png \
		../../IMAGENES/CANTIDAD.png \
		../../IMAGENES/operario.png \
		../../IMAGENES/estadisticas.png \
		../../IMAGENES/eliminarArchivo.png \
		../../IMAGENES/APAGAR.png \
		../../IMAGENES/exit.png \
		../../IMAGENES/MANTENIMIENTO.png \
		../../IMAGENES/guardar.png \
		../../IMAGENES/CARGAR.png
	c:/Qt/4.8.6/bin/rcc.exe -name Imagenes ../../IMAGENES/Imagenes.qrc -o qrc_Imagenes.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_pantallaprincipal.h
compiler_uic_clean:
	-$(DEL_FILE) ui_pantallaprincipal.h
ui_pantallaprincipal.h: pantallaprincipal.ui
	c:/Qt/4.8.6/bin/uic.exe pantallaprincipal.ui -o ui_pantallaprincipal.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: main.cpp pantallaprincipal.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

pantallaprincipal.o: pantallaprincipal.cpp pantallaprincipal.h \
		ui_pantallaprincipal.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o pantallaprincipal.o pantallaprincipal.cpp

moc_pantallaprincipal.o: moc_pantallaprincipal.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_pantallaprincipal.o moc_pantallaprincipal.cpp

qrc_Imagenes.o: qrc_Imagenes.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_Imagenes.o qrc_Imagenes.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

