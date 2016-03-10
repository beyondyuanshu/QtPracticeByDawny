#-------------------------------------------------
#
# Project created by QtCreator 2016-03-04T10:12:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtPracticeByDawny
TEMPLATE = app

DEFINES += CMD_DEBUG
CONFIG += console

INCLUDEPATH += $$PWD/curl/include/curl
INCLUDEPATH += $$PWD/zdm2
INCLUDEPATH += $$PWD/QJson

win32:CONFIG(release, debug|release): {
    LIBS += -L"$$PWD/curl/lib" -llibcurl
}

win32:CONFIG(debug, debug|release): {
    LIBS += -L"$$PWD/curl/lib" -llibcurld
}

SOURCES += main.cpp\
        mainwindow.cpp \
    ticker.cpp \
    zdm2/zdmhttp.cpp \
    zdm2/zdmhttpex.cpp \
    zdmhttptest.cpp \
    QJson/json_scanner.cpp \
    QJson/parser.cpp \
    QJson/serializer.cpp \
    QJson/parserrunnable.cpp \
    QJson/serializerrunnable.cpp \
    QJson/json_parser.cc \
    QJson/json_scanner.cc \
    QJson/qobjecthelper.cpp \
    zlog.cpp

HEADERS  += mainwindow.h \
    zstring.h \
    cfunctions.h \
    dbg_byZed.h \
    ticker.h \
    zdm2/zdmhttp.h \
    zdm2/zdmhttpex.h \
    zdmhttptest.h \
    QJson/json_scanner.h \
    QJson/parser.h \
    QJson/serializer.h \
    QJson/parserrunnable.h \
    QJson/serializerrunnable.h \
    QJson/FlexLexer.h \
    QJson/json_parser.hh \
    QJson/location.hh \
    QJson/parser_p.h \
    QJson/position.hh \
    QJson/qjson_debug.h \
    QJson/qjson_export.h \
    QJson/qobjecthelper.h \
    QJson/stack.hh \
    zlog.h

FORMS    += mainwindow.ui
