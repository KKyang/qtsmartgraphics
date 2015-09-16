#-------------------------------------------------
#
# Project created by QtCreator 2014-10-26T23:34:15
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qsmartgraphicsview
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../../qsmartgraphicsview.cpp

HEADERS  += mainwindow.h \
    ../../qsmartgraphicsview.h

FORMS    += mainwindow.ui

INCLUDEPATH += $$quote(../../)
