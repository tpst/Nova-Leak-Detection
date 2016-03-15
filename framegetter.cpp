#include "framegetter.h"

using namespace cv;
using namespace FlyCapture2;

frameGetter::frameGetter(FlyCapture2::Camera &cam)
{
    cv = false;
    camera = &cam;
    streaming = true;
}

frameGetter::frameGetter(cv::VideoCapture &cap)
{
    cv = true;
    vc = &cap;
    streaming = true;
}

frameGetter::~frameGetter()
{

}

void frameGetter::process()
{
    while(streaming)
    {
        try {
            // get an image
            if(cv)
            {
                if(vc->isOpened()) {
                    if(!vc->read(frame)) {
                        qDebug() << "Cannot get image from stream 2";
                    } else {
                        emit procFrame(frame); // process this image
                        //frame 1
                        qFrame = convertFrame(frame);
                        emit frameReady(qFrame);
                        this->msleep(5);
                    }
                } else {
                    streaming = false;
                }
            } else {
                Image rawImage;
                FlyCapture2::Error error = camera->RetrieveBuffer( &rawImage );
                if ( error != PGRERROR_OK )
                {
                   // std::cout << "capture error" << std::endl;

                    //qDebug() << "FlyCam Capture Error";
                    continue;
                }

                // convert to rgb
                Image rgbImage;
                rawImage.Convert( FlyCapture2::PIXEL_FORMAT_BGR, &rgbImage );

                // convert to OpenCV Mat
                unsigned int rowBytes = (double)rgbImage.GetReceivedDataSize()/(double)rgbImage.GetRows();
                cv::Mat image = cv::Mat(rgbImage.GetRows(), rgbImage.GetCols(), CV_8UC3, rgbImage.GetData(),rowBytes);

                //this->rotate(image, 90, image);

                qFrame = convertFrame(image);
                emit frameReady(qFrame);
                this->msleep(5);

            }
        } catch(std::exception &e) {
            streaming = false;
            qDebug() << "Framegetter failed to capture an image.";
        }
    }
    emit refreshDisplays();
}

void frameGetter::endStream()
{
    streaming = false;
    emit finished();
}

void frameGetter::msleep(int ms)
{
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
}

QImage frameGetter::convertFrame(cv::Mat frame)
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

/**
 * Rotate an image
 */
void frameGetter::rotate(cv::Mat& src, double angle, cv::Mat& dst)
{
    int len = std::max(src.cols, src.rows);
    cv::Point2f pt(len/2., len/2.);
    cv::Mat r = cv::getRotationMatrix2D(pt, angle, 1.0);

    cv::warpAffine(src, dst, r, cv::Size(len, len));
}
