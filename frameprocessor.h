#ifndef FRAMEPROCESSOR_H
#define FRAMEPROCESSOR_H

#include <QObject>
#include <QDebug>
#include <QImage>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "variables.h"

// Image processing worker class
class frameProcessor : public QObject
{
    Q_OBJECT
public:
    frameProcessor(bool &on);
    ~frameProcessor();
    QImage convertFrame(cv::Mat frame);

    void loadFromFile(); //testing
    void init();

public slots:
    void process(cv::Mat frame);
    void updateThresh(int value);
    void testProcess(cv::Mat _frame);
    void copyVariables(variables _values);

signals:
    void finished();
    void frameReady(QImage qFrame);

private:
    //variables
    QImage qFrame;
    cv::Mat frame, RGBframe;
    cv::Mat frameClone, dst; // result frame
    cv::Mat frameC; //contrast frame

    cv::VideoCapture vc;

    bool *run;
    int thresh;

    void detectLeaks(cv::Mat& frame);

    variables values;

};


#endif // FRAMEPROCESSOR_H
