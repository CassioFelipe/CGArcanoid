#-------------------------------------------------
#
# Project created by QtCreator 2015-04-28T18:27:25
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lesson1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myglwidget.cpp \
    vetor2d.cpp

HEADERS  += mainwindow.h \
    myglwidget.h \
    vetor2d.h

FORMS    += mainwindow.ui
