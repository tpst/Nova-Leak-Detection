#ifndef TEST_H
#define TEST_H

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <QObject>
#include <QDebug>

class test : public QObject
{
    Q_OBJECT
public:
    test();
    void msleep(int ms);

    ~test();
public slots:
    void process();
signals:
    void procFrame(cv::Mat frame);
public:
    cv::Mat frame;
    cv::VideoCapture vc;
    bool on;
};

#endif // TEST_H
