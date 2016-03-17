#include "frameprocessor.h"
#include <QTimer>

using namespace cv;

void msleep(int ms)
{
#ifdef unix
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
#endif
#if defined(_MSC_VER) || defined(WIN32)  || defined(_WIN32) || defined(__WIN32__) \
|| defined(WIN64) || defined(_WIN64) || defined(__WIN64__)
    Sleep(ms);
#endif
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
           // detectLeaks(frame);
            //qFrame = convertFrame(frame);
            //emit frameReady(qFrame);
        }
    } catch(std::exception &e) {
        qDebug() << "Image processing failed";
    }
}

void frameProcessor::testProcess(cv::Mat _frame)
{
    //msleep(20);
    detectLeaks(_frame);
    //qFrame = convertFrame(_frame);
    //emit frameReady(qFrame);
}

Mat frameProcessor::crop(Mat frame) {
    double x = frame.cols*(values.var.x/100);
    double y = frame.rows*(values.var.y/100);
    double width = frame.cols*(values.var.width/100);
    double height = frame.rows*(values.var.height/100);

    if((x+width) >= frame.cols) {
        width -= (x+width - frame.cols+1);
    }
    if((y+height) >= frame.rows) {
        height -= (y+height - frame.rows+1);
    }


    Mat crop = frame.clone()(Rect(x, y, width, height));
    line(frame, Point(x,y), Point(x,y+height), Scalar(0,255,255), 2);
    line(frame, Point(x+width,y), Point(x+width,y+height), Scalar(0,255,255),2);
    line(frame, Point(x, y), Point(x+width,y), Scalar(0,255,255),2);
    line(frame, Point(x,y+height),Point(x+width,y+height),Scalar(0,255,255),2);
    emit displayCrop(frame);

    return crop;
}

void frameProcessor::detectLeaks(Mat frame)
{
    try {
        cvtColor(frame, frame, CV_BGR2GRAY);
        frameClone = frame.clone();
        frame = crop(frame);

        // Sharpen image
        GaussianBlur(frame, dst, Size(values.var.size, values.var.size), (double)values.var.sigmaX/1000);
        addWeighted(frame, (double)values.var.alpha/1000, dst, (double)-values.var.beta/1000,
                    (double)values.var.gamma/1000, dst);
        sharpened = dst.clone();
        emit displaySharpen(sharpened);


        equalizeHist(dst, dst);
        // change image contrast
        dst.convertTo(dst, -1, (double)values.var.scale/1000, (double)values.var.betaC/1000);
        contrast = dst.clone();
        emit displayContrast(contrast);

        threshold(dst, dst, values.var.thresh, 255, CV_THRESH_BINARY_INV);
        element = getStructuringElement( MORPH_RECT, Size(values.var.sSize, values.var.sSize),
                                         Point(-1, -1) );
        morphologyEx(dst, dst, MORPH_CLOSE, element);
        thresholded = dst.clone();
        emit displayThresh(thresholded);

        // find pipe here
        element = getStructuringElement( MORPH_RECT, Size(values.var.ssSizeX, values.var.ssSizeY),
                                         Point(-1, -1) );
        morphologyEx(dst, dst, MORPH_OPEN, element);

        opened = dst.clone();
        emit displayOpen(opened);
        std::vector< std::vector< Point > > contours;
        findContours(dst.clone(), contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

        if(contours.size() > 0)
        {
            for( int i = 0; i < contours.size(); i++)
            {
                if(contourArea(contours[i]) < 100)
                {
                    Rect boundRect = boundingRect(contours[i]);
                    Point tl = Point(boundRect.tl().x+frameClone.cols*values.var.x/100,
                                     boundRect.tl().y+frameClone.rows*values.var.y/100);
                    Point br = Point(boundRect.br().x+frameClone.cols*values.var.x/100,
                                     boundRect.br().y+frameClone.rows*values.var.y/100);
                    rectangle( frameClone, tl, br, Scalar(255,255,0), 2);
                }
            }
        }
        emit displayResult(frameClone);


    } catch(std::exception &e) {
        qDebug() << "Leak detection error: " << e.what();
    }
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


