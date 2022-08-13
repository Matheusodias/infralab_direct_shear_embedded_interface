QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES += src/tst_sockettests.cpp \
    src/machineclient.cpp \
    src/machineserver.cpp \
    ../Interface/src/receivedata.cpp \
    ../Interface/src/threadcontroller.cpp \
    ../Interface/src/sendcommands.cpp


HEADERS += \
    ../Interface/inc/receivedata.h \
    ../Interface/inc/socket_local.h \
    ../Interface/inc/threadcontroller.h \
    ../Interface/inc/sendcommands.h \
    inc/machineclient.h \
    inc/machineserver.h

