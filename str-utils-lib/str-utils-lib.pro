#-------------------------------------------------
#
# Project created by QtCreator 2020-07-22T11:04:06
#
#-------------------------------------------------

QT       -= core gui

TARGET = str-utils
TEMPLATE = lib
CONFIG += staticlib \
          c++14     \
          release

VPATH       += $$PWD/src \
               $$PWD/inc
SOURCES     += strutils.cpp
HEADERS     += strutils.h

INCLUDEPATH += $$PWD/inc
DESTDIR      = $$PWD/lib

!build_pass:message(" --- StrUtils static library --- ")
!build_pass:warning(" This library requires the support of Cxx-14 ")

unix {
    target.path = /usr/lib
    INSTALLS += target
}
