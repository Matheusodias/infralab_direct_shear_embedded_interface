QT += testlib
QT += core gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES += \
    ../Interface/src/receivedata.cpp \
    ../Interface/src/sendcommands.cpp \
    ../Interface/src/threadcontroller.cpp \
    src/machineclient.cpp \
    src/machineserver.cpp \
    src/tst_sockettests.cpp



HEADERS += \
    ../Interface/inc/receivedata.h \
    ../Interface/inc/sendcommands.h \
    ../Interface/inc/socket_local.h \
    ../Interface/inc/threadcontroller.h \
    inc/machineclient.h \
    inc/machineserver.h


