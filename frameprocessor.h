#ifndef FRAMEPROCESSOR_H
#define FRAMEPROCESSOR_H

#include <QObject>
#include <QDebug>
#include <QImage>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

// Image processing worker class
class frameProcessor : public QObject
{
    Q_OBJECT
public:
    frameProcessor(bool &on);
    ~frameProcessor();

public slots:
    void process(cv::Mat frame);

signals:
    void finished();
    void frameReady(QImage qFrame);

private:
    //variables
    QImage qFrame;
    cv::Mat frame;
    bool *run;
};

#endif // FRAMEPROCESSOR_H
