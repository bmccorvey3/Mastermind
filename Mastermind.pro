#-------------------------------------------------
#
# Project created by QtCreator 2014-07-10T12:40:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mastermind
TEMPLATE = app


SOURCES += main.cpp\
    peg.cpp \
    pegpanel.cpp \
    plug.cpp \
    row.cpp \
    dealer.cpp \
    pin.cpp \
    pinpanel.cpp \
    button.cpp

HEADERS  += \
    peg.h \
    pegpanel.h \
    plug.h \
    row.h \
    dealer.h \
    pin.h \
    pinpanel.h \
    button.h

FORMS    += mainwindow.ui
QMAKE_CXXFLAGS += -std=c++11
CONFIG += console
