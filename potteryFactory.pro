#-------------------------------------------------
#
# Project created by QtCreator 2018-03-22T09:38:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = potteryFactory
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    obiekt.cpp \
    observer.cpp \
    pi.cpp \
    qcustomplot.cpp \
    regulator.cpp \
    subject.cpp

HEADERS += \
        mainwindow.h \
    mainwindow.h \
    obiekt.h \
    observer.h \
    pi.h \
    qcustomplot.h \
    regulator.h \
    subject.h

FORMS += \
        mainwindow.ui \
    mainwindow.ui

SUBDIRS += \
    potteryFactory.pro

DISTFILES += \
    potteryFactory.pro.user
