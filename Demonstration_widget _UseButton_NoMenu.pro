#-------------------------------------------------
#
# Project created by QtCreator 2018-06-28T19:24:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Demonstration_widget _UseButton_NoMenu
TEMPLATE = app
DESTDIR = $$PWD/bin

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        demonstration_widget.cpp \
    sub_GUI/pathdialog.cpp \
    sub_GUI/automodedialog.cpp \
    sub_GUI/manualdialog.cpp \
    sub_GUI/datashowdialog.cpp

HEADERS  += demonstration_widget.h \
    sub_GUI/pathdialog.h \
    sub_GUI/automodedialog.h \
    sub_GUI/manualdialog.h \
    sub_GUI/datashowdialog.h

FORMS    += demonstration_widget.ui \
    sub_GUI/pathdialog.ui \
    sub_GUI/automodedialog.ui \
    sub_GUI/manualdialog.ui \
    sub_GUI/datashowdialog.ui

RESOURCES += \
    img/images.qrc
