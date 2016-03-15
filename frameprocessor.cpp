#include "frameprocessor.h"
#include <QTimer>

using namespace cv;

void msleep(int ms)
{
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
}

frameProcessor::frameProcessor(bool &on)
{
    run = &on;
    init();
}

frameProcessor::~frameProcessor()
{
    // free resources
}

void frameProcessor::init()
{

}

void frameProcessor::process(Mat frame)
{

    try
    {
        if(*run)
        {
            // image processing goes here
            detectLeaks(frame);
            qFrame = convertFrame(frame);
            emit frameReady(qFrame);
        } else {
            emit finished();
        }
    } catch(std::exception &e) {
        qDebug() << "Image processing failed";
    }
}

void frameProcessor::testProcess(cv::Mat _frame)
{
       if(_frame.rows > 0) {
            //msleep(20);
            detectLeaks(_frame);
            //qFrame = convertFrame(_frame);
            //emit frameReady(qFrame);
       }
}

void frameProcessor::detectLeaks(Mat &frame)
{

    frameClone = frame.clone();
    cvtColor(frame, frame, CV_BGR2GRAY);

    //qDebug() << values.var.gamma;
    // Sharpen image
    GaussianBlur(frame, dst, Size(values.var.size, values.var.size), (double)values.var.sigmaX/1000);
    addWeighted(frame, (double)values.var.alpha/1000, dst, (double)-values.var.beta/1000, (double)values.var.gamma/1000, dst);

    qFrame = convertFrame(dst);
    emit frameReady(qFrame);
    // show sharpen
}

void frameProcessor::copyVariables(variables _values)
{
    values.var = _values.var;
}

void frameProcessor::updateThresh(int value)
{
    thresh = value;
}

void frameProcessor::loadFromFile()
{
    vc.open("/home/zzaj/Videos/Nova Leak Videos/Latest/1.asf");
    if(!vc.isOpened())
        qDebug() << "Failed to open video";
}

QImage frameProcessor::convertFrame(cv::Mat frame)
{
    QImage _qFrame;
    if (frame.channels()== 3){
        cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
        _qFrame = QImage((const unsigned char*)(RGBframe.data),
                          RGBframe.cols,RGBframe.rows,QImage::Format_RGB888);
    }
    else
    {
        _qFrame = QImage((const unsigned char*)(frame.data),
                             frame.cols,frame.rows,QImage::Format_Indexed8);
    }
    return _qFrame;
}
