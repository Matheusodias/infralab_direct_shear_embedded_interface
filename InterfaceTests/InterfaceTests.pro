QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES += tst_sockettests.cpp \
    ../Interface/receivedata.cpp \
    ../Interface/threadcontroller.cpp \
    ../Interface/sendcommands.cpp \
    machineclient.cpp \
    machineserver.cpp


HEADERS += \
    ../Interface/receivedata.h \
    ../Interface/socket_local.h \
    ../Interface/threadcontroller.h \
    machineclient.h \
    machineserver.h \
    ../Interface/sendcommands.h
