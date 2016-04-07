QT += core
QT -= gui

CONFIG += c++11

TARGET = runonce
CONFIG += console
CONFIG -= app_bundle

include(../../01src/libs/kdtools/kdtools.pri)

TEMPLATE = app

SOURCES += $$PWD/main.cpp
