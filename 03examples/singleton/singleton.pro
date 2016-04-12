QT += core
QT -= gui

CONFIG += c++11

TARGET = runonce
CONFIG += console
CONFIG -= app_bundle

include(../../01src/sdk/includes/inc.pri)

TEMPLATE = app

SOURCES += $$PWD/main.cpp \
    zsingletonhelper.cpp

HEADERS += \
    zsingletonhelper.h
