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

INCLUDEPATH += \
        headers/ \
        headers/controller/ \
        headers/crew/ \
        headers/data_structure/ \
        headers/file_handler/ \
        headers/gui/ \
        headers/materials/ \
        headers/projects/

SOURCES += \
        src/main.cpp \
        src/gui/mainwindow.cpp \
        src/materials/material.cpp \
        src/projects/project.cpp \
        src/crew/crew.cpp \
        src/materials/frameaspect.cpp \
        src/materials/packaging.cpp \
        src/materials/dvd.cpp \
        src/materials/twosideddvd.cpp \
        src/materials/singlesideddvd.cpp \
        src/materials/bluray.cpp \
        src/materials/vhs.cpp \
        src/materials/combobox.cpp \
        src/crew/director.cpp \
        src/crew/producer.cpp \
        src/crew/writer.cpp \
        src/crew/editor.cpp \
        src/crew/actor.cpp \
        src/crew/productiondesigner.cpp \
        src/crew/setdecorator.cpp \
        src/crew/costumedesigner.cpp \
        src/data_structure/node.cpp \
        src/data_structure/doublylinkedlist.cpp \
        src/file_handler/filehandler.cpp \
        src/gui/stylesheetreader.cpp

HEADERS += \
        headers/gui/mainwindow.h \
        headers/materials/material.h \
        headers/projects/project.h \
        headers/crew/crew.h \
        headers/materials/frameaspect.h \
        headers/materials/packaging.h \
        headers/materials/dvd.h \
        headers/materials/twosideddvd.h \
        headers/materials/singlesideddvd.h \
        headers/materials/bluray.h \
        headers/materials/vhs.h \
        headers/materials/combobox.h \
        headers/crew/director.h \
        headers/crew/producer.h \
        headers/crew/writer.h \
        headers/crew/editor.h \
        headers/crew/actor.h \
        headers/crew/productiondesigner.h \
        headers/crew/setdecorator.h \
        headers/crew/costumedesigner.h \
        headers/data_structure/node.h \
        headers/data_structure/doublylinkedlist.h \
        headers/file_handler/filehandler.h \
        headers/main.h \
        headers/gui/gui.h

FORMS += \
        forms/mainwindow.ui

RESOURCES += \
    style/styleVariables.txt \
    style/main.qss

