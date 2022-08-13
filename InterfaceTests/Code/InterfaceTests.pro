QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES += src/tst_sockettests.cpp \
    src/machineclient.cpp \
    src/machineserver.cpp \
    ../../Interface/Code/src/receivedata.cpp \
    ../../Interface/Code/src/threadcontroller.cpp \
    ../../Interface/Code/src/sendcommands.cpp


HEADERS += \
    ../../Interface/Code/inc/receivedata.h \
    ../../Interface/Code/inc/socket_local.h \
    ../../Interface/Code/inc/threadcontroller.h \
    ../../Interface/Code/inc/sendcommands.h \
    inc/machineclient.h \
    inc/machineserver.h

