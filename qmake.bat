@echo off
set QMAKESPEC=C:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot/usr/share/qt4/mkspecs/arm-linux-gnueabihf
set PATH=%PATH%;C:\SysGCC\Raspberry\bin
C:\SysGCC\Raspberry\bin\qmake.exe %*
