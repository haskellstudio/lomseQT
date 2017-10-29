#-------------------------------------------------
#
# Project created by QtCreator 2017-10-29T14:49:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lomseQT
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += /Users/zhufei/dev/lomse/include
INCLUDEPATH += /Users/zhufei/dev/lomse/build
INCLUDEPATH += /Users/zhufei/dev/lomse/src/agg/include
INCLUDEPATH += /usr/local/include
INCLUDEPATH += /usr/local/include/freetype2

LIBS += /usr/local/Cellar/boost/1.65.1/lib/libboost_system.a
LIBS += /Users/zhufei/dev/lomse/build/bin/Debug/liblomse.0.20.0.so

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui
