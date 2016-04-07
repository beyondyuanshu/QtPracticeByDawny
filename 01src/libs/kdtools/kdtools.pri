INCLUDEPATH += $$PWD

DEFINES += BUILD_SHARED_KDTOOLS

LIBS += -lole32 -lshell32 -lmpr -lAdvapi32 -luser32 -lmsvcrt

FORMS +=

HEADERS += $$PWD/kdtoolsglobal.h \
    $$PWD/kdselfrestarter.h \
    $$PWD/kdrunoncechecker.h \
    $$PWD/kdlockfile.h \
    $$PWD/kdsysinfo.h \
    $$PWD/link.h

SOURCES += $$PWD/kdselfrestarter.cpp \
    $$PWD/kdrunoncechecker.cpp \
    $$PWD/kdlockfile.cpp \
    $$PWD/kdsysinfo.cpp \
    $$PWD/sysinfo_win.cpp \
    $$PWD/link.cpp

HEADERS +=

SOURCES +=

unix:SOURCES += $$PWD/kdlockfile_unix.cpp
win32:SOURCES += $$PWD/kdlockfile_win.cpp
win32:SOURCES += $$PWD/kdsysinfo_win.cpp
macx:SOURCES += $$PWD/kdsysinfo_mac.cpp
unix:!macx:SOURCES += $$PWD/kdsysinfo_x11.cpp
