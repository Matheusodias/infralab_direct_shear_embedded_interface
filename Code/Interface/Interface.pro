QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/experiment_mutable_variables.cpp \
    src/field.cpp \
    src/sample.cpp \
    src/button.cpp \
    src/experiment.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/receivedata.cpp \
    src/sendcommands.cpp \
    src/threadcontroller.cpp

HEADERS += \
    inc/experiment_mutable_variables.h \
    inc/field.h \
    inc/button.h \
    inc/mainwindow.h \
    inc/receivedata.h \
    inc/sendcommands.h \
    inc/socket_local.h \
    inc/threadcontroller.h \
    inc/experiment.h \
    inc/sample.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images/resources.qrc

DISTFILES +=
