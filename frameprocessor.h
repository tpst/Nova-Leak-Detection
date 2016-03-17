#ifndef FRAMEPROCESSOR_H
#define FRAMEPROCESSOR_H
#if defined(_MSC_VER) || defined(WIN32)  || defined(_WIN32) || defined(__WIN32__) \
    || defined(WIN64) || defined(_WIN64) || defined(__WIN64__)

#include <windows.h>
#endif
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

    void displaySharpen(cv::Mat frame);
    void displayContrast(cv::Mat frame);
    void displayThresh(cv::Mat frame);
    void displayOpen(cv::Mat frame);
    void displayResult(cv::Mat frame);
    void displayCrop(cv::Mat frame);

private:
    //variables
    QImage qFrame;
    cv::Mat frameClone, dst; // result frame
    cv::Mat element; // structuring element

    cv::Mat sharpened;
    cv::Mat contrast;
    cv::Mat thresholded;
    cv::Mat opened;

    cv::VideoCapture vc;

    bool *run;
    int thresh;

    void detectLeaks(cv::Mat frame);
    cv::Mat crop(cv::Mat frame);

    variables values;

};


#endif // FRAMEPROCESSOR_H
