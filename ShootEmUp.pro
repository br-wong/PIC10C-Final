#-------------------------------------------------
#
# Project created by QtCreator 2016-11-16T11:51:54
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ShootEmUp
TEMPLATE = app

SOURCES += main.cpp \
    Shooter.cpp \
    Bullet.cpp \
    Target.cpp \
    Game.cpp \
    Score.cpp \
    Health.cpp \
    Mainwindow.cpp

HEADERS  += \
    Shooter.h \
    Bullet.h \
    Target.h \
    Game.h \
    Score.h \
    Health.h \
    Mainwindow.h

FORMS    += \
    Mainwindow.ui

RESOURCES += \
    assets.qrc
