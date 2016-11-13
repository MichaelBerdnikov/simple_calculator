#-------------------------------------------------
#
# Project created by QtCreator 2016-09-22T22:13:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = simple_calculator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    action.cpp \
    propertywindow.cpp \
    configuration.cpp \
    currencyconverter.cpp

HEADERS  += mainwindow.h \
    action.h \
    propertywindow.h \
    configuration.h \
    currencyconverter.h

FORMS    += mainwindow.ui
