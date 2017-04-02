#-------------------------------------------------
#
# Project created by QtCreator 2016-09-05T15:18:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = forum
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    post.cpp \
    comment.cpp \
    allinfo.cpp \
    personinfo.cpp \
    setboardmanagerdialog.cpp \
    delboardmanagerdialog.cpp \
    inpostdialog.cpp

HEADERS  += mainwindow.h \
    user.h \
    logindialog.h \
    post.h \
    comment.h \
    datastructure.h \
    allinfo.h \
    personinfo.h \
    setboardmanagerdialog.h \
    delboardmanagerdialog.h \
    inpostdialog.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    allinfo.ui \
    personinfo.ui \
    setboardmanagerdialog.ui \
    delboardmanagerdialog.ui \
    inpostdialog.ui

DISTFILES +=

CONFIG += c++11

RESOURCES += \
    resource.qrc

UI_DIR += mainwindow.ui \
    user.ui \
    logindialog.ui \
    post.ui \
    comment.ui \
    datastructure.ui \
    allinfo.ui \
    personinfo.ui \
    setboardmanagerdialog.ui \
    delboardmanagerdialog.ui \
    inpostdialog.ui

