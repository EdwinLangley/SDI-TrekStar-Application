#-------------------------------------------------
#
# Project created by QtCreator 2018-02-25T18:53:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrekStarApp
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

INCLUDEPATH += headers/

SOURCES += \
        src/main.cpp \
        src/mainwindow.cpp \
        src/material.cpp \
        src/project.cpp \
        src/crew.cpp \
        src/frameaspect.cpp \
        src/packaging.cpp \
        src/dvd.cpp \
        src/twosideddvd.cpp \
        src/singlesideddvd.cpp \
        src/bluray.cpp \
        src/vhs.cpp \
        src/combobox.cpp \
        src/director.cpp \
        src/producer.cpp \
        src/writer.cpp \
        src/editor.cpp \
        src/actor.cpp \
        src/productiondesigner.cpp \
        src/setdecorator.cpp \
        src/costumedesigner.cpp \
        src/node.cpp \
        src/doublylinkedlist.cpp \
        src/filehandler.cpp \

HEADERS += \
        headers/mainwindow.h \
        headers/material.h \
        headers/project.h \
        headers/crew.h \
        headers/frameaspect.h \
        headers/packaging.h \
        headers/dvd.h \
        headers/twosideddvd.h \
        headers/singlesideddvd.h \
        headers/bluray.h \
        headers/vhs.h \
        headers/combobox.h \
        headers/director.h \
        headers/producer.h \
        headers/writer.h \
        headers/editor.h \
        headers/actor.h \
        headers/productiondesigner.h \
        headers/setdecorator.h \
        headers/costumedesigner.h \
        headers/node.h \
        headers/doublylinkedlist.h \
        headers/filehandler.h

FORMS += \
        forms/mainwindow.ui
