#-------------------------------------------------
#
# Project created by QtCreator 2016-02-25T11:51:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LeakDetection
TEMPLATE = app

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_videoio -lopencv_imgproc
LIBS += -L/usr/lib -lflycapture -lflycapture-c -lflycapturegui

SOURCES += main.cpp\
        mainwindow.cpp \
    capturehandler.cpp \
    configdialog.cpp \
    streamconnector.cpp \
    framegetter.cpp \
    frameprocessor.cpp

HEADERS  += mainwindow.h \
    capturehandler.h \
    configdialog.h \
    streamconnector.h \
    framegetter.h \
    frameprocessor.h

FORMS    += \
    mainwindow.ui \
    configdialog.ui
