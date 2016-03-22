#ifndef FRAMEGETTER_H
#define FRAMEGETTER_H

#if defined(_MSC_VER) || defined(WIN32)  || defined(_WIN32) || defined(__WIN32__) \
    || defined(WIN64) || defined(_WIN64) || defined(__WIN64__)

#include <windows.h>
#endif
#include <memory>
#include <QObject>
#include <QDebug>
#include <QImage>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

//#include <flycapture/FlyCapture2.h>

// Worker class responsible for grabbing a frame from stream
class frameGetter : public QObject
{
    Q_OBJECT
public:
    //frameGetter(FlyCapture2::Camera &cam);
    frameGetter(bool ip);
    ~frameGetter();
    void rotate(cv::Mat& src, double angle, cv::Mat& dst);
    QImage convertFrame(cv::Mat frame);
    bool openFlyCam();
    int newConnection(QString IP);
    void msleep(int ms);

public slots:
    void process();
    void endStream();
signals:
    void finished();
    void frameReady(QImage frame);
    void procFrame(cv::Mat frame);
    void refreshDisplays();

private:
    //variables
    bool cv; // controls whether process uses opencv or flycam
    bool streaming;
    //FlyCapture2::Camera *camera;
    cv::VideoCapture *vc;
    //std::unique_ptr<vc::VideoCapture> vc;

    QImage qFrame;
    cv::Mat RGBframe;
};

#endif // FRAMEGETTER_H
