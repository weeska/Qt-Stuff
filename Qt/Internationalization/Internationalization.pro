#-------------------------------------------------
#
# Project created by QtCreator 2015-05-15T17:24:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Internationalization
TEMPLATE = app

TRANSLATIONS += \
        translation_en_EN.ts \
        translation_de_DE.ts \

SOURCES += main.cpp\
        MainWindow.cpp

HEADERS  += MainWindow.h

FORMS    += MainWindow.ui

RESOURCES += \
    resources.qrc

DISTFILES +=
