#-------------------------------------------------
#
# Project created by QtCreator 2016-02-25T11:51:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LeakDetection
TEMPLATE = app

CONFIG+=static

#INCLUDEPATH += -I/home/zzaj/src/mxe/usr/i686-w64-mingw32.static/include
#LIBS += -L/home/zzaj/src/mxe/usr/i686-w64-mingw32.static/lib -lopencv_shape300 -lopencv_stitching300 -lopencv_objdetect300 -lopencv_superres300 -lopencv_videostab300 -lopencv_calib3d300 -lopencv_features2d300 -lopencv_highgui300 -lopencv_videoio300 -lopencv_imgcodecs300 -lopencv_video300 -lopencv_photo300 -lopencv_ml300 -lopencv_imgproc300 -lopencv_flann300 -lopencv_core300 -lvfw32 -lmsvfw32 -lopencv_hal300


INCLUDEPATH += /usr/local/include/
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_videoio -lopencv_imgproc

#LIBS += -L/usr/lib -lflycapture -lflycapture-c -lflycapturegui

SOURCES += main.cpp\
        mainwindow.cpp \
    capturehandler.cpp \
    configdialog.cpp \
    streamconnector.cpp \
    framegetter.cpp \
    frameprocessor.cpp \
    cvconfig.cpp \
    variables.cpp \
    test.cpp

HEADERS  += mainwindow.h \
    capturehandler.h \
    configdialog.h \
    streamconnector.h \
    framegetter.h \
    frameprocessor.h \
    cvconfig.h \
    variables.h \
    test.h

FORMS    += \
    mainwindow.ui \
    configdialog.ui \
    cvconfig.ui
