#ifndef FRAMEGETTER_H
#define FRAMEGETTER_H

#include <QObject>
#include <QDebug>
#include <QImage>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <flycapture/FlyCapture2.h>

// Worker class responsible for grabbing a frame from stream
class frameGetter : public QObject
{
    Q_OBJECT
public:
    frameGetter(FlyCapture2::Camera &cam);
    frameGetter(cv::VideoCapture &cap);
    ~frameGetter();
    void rotate(cv::Mat& src, double angle, cv::Mat& dst);
    QImage convertFrame(cv::Mat frame);

public slots:
    void process();
    void endStream();
signals:
    void finished();
    void frameReady(QImage frame);
    void procFrame(cv::Mat frame);
    void refreshDisplays();
    void error(QString err);

protected:
    void msleep(int ms);
private:
    //variables
    bool cv; // controls whether process uses opencv or flycam
    bool streaming;
    FlyCapture2::Camera *camera;
    cv::VideoCapture *vc;

    QImage qFrame;
    cv::Mat frame, RGBframe;
};

#endif // FRAMEGETTER_H
