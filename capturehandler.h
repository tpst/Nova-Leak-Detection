#ifndef CAPTUREHANDLER_H
#define CAPTUREHANDLER_H

#if defined(_MSC_VER) || defined(WIN32)  || defined(_WIN32) || defined(__WIN32__) \
    || defined(WIN64) || defined(_WIN64) || defined(__WIN64__)

#include <windows.h>
#endif


#include <QObject>
#include <QThread>
#include <QImage>
#include <QDebug>
#include <QTimer>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>

#include "framegetter.h"
#include "variables.h"
#include "frameprocessor.h"
\
//#include <flycapture/FlyCapture2.h>
#include <iostream>

using namespace cv;
//using namespace FlyCapture2;

class captureHandler : public QThread
{
    Q_OBJECT
public:
    captureHandler(QObject *parent = 0);
    ~captureHandler();


    //Record current stream
    void recordStream();
    //check if stream is stopped
    bool isStopped();
    //Stop stream
    void Stop();

    void toggleStream1(bool value);

    void toggleStream2(bool value);

    void toggleProcess(bool value);

    void toggleRecord(bool value);

    bool isProcessActive();

    bool isRecording();

    bool isStream1Active();

    bool isStream2Active();

    bool openFlyCam();

    bool newConnection(cv::VideoCapture &capture, QString address);

    QString IP1, IP2;

    frameGetter* get1;
    frameGetter* get2;

public slots:
    //Initiate video stream
    void playStream();
    void endStreams();

private:
    bool stream1Active;
    bool stream2Active;
    bool processActive;
    bool stop;
    bool record;

    Mat frame, frame2, RGBframe;
    QImage qFrame, qFrame2;

    VideoCapture vc;
    VideoCapture vc2;
    //Camera camera;

    // Seperate threads for image capture and processing
    QThread* thread1;
    QThread* thread2;
    QThread* thread3;

    // frame processing logic
    frameProcessor* proc; // configuration
    frameProcessor* proc2; // for mainwindow - copys cfg settings
    bool on;
    bool connected;

    bool init; // only init captures once.

protected:
    void run();
    void msleep(int ms);

signals:
    void frameReady(QImage frame);
    void frameReady2(QImage frame2);
    void saveStream(cv::Mat frame);
    void streamOver();
    void startStream();
    void refreshDisplays();
    void applySettings(variables v);

};

#endif // CAPTUREHANDLER_H
