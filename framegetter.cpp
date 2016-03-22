// new framegetter

#include "framegetter.h"
#include "streamconnector.h"
#include "iostream"
#include <memory>

#include <QThread>

using namespace cv;
// using namespace FlyCapture2;

// framegetter class will open FlyCapture camera by default, unless CV flag is toggled and connect to an IP
frameGetter::frameGetter(bool ip = false)
{
    cv = ip;
    vc = new VideoCapture();
    //std::shared_ptr<VideoCapture> myPtr;

}

frameGetter::~frameGetter() 
{
}

int frameGetter::newConnection(QString IP)
{

    std::cout << "newConnection: " << QThread::currentThreadId() << std::endl;
    try {
        if(!vc->isOpened())
        {
            vc = new VideoCapture();

            std::cout << "Opening ";
            std::cout << IP.toStdString() << std::endl;

            if(IP == "http://.../mjpg/video.mjpg") {
                vc->open(0); // open default webcam
            } else {
                vc->open(IP.toStdString());
            }

        } else {
            std::cout << "Already open" << std::endl;
        }
        if(vc->isOpened()) {
//            Mat frame;
//            vc->read(frame);
//            imshow("frame", frame);
//            waitKey(0);
            streaming = true;
            return true;
        } else {
            return false;
        }
    } catch(std::exception &e) {
        qDebug() << "Stream could not connect. Returned error: " << e.what();
        return false;
    }
}

void frameGetter::process()
{
    std::cout << "get process: " << QThread::currentThreadId() << std::endl;
    std::cout << "capture object: " << &vc << std::endl;
    try {
         while(streaming) {
            this->msleep(20);
            if(cv) {
                Mat frame;
                if(vc->isOpened()) {
                    if(!vc->read(frame)) {
                        std::cout << "Could not get image from camera" << std::endl;
                    } else {
                        // emit procFrame(frame);
                        qFrame = convertFrame(frame);
                        emit frameReady(qFrame);
                    }
                } else {
                    streaming = false;
                    std::cout << "framegetter capture not open" << std::endl;
                }
            } else {
                // stupid flycam
            }
         }

    } catch(std::exception &e) {
        std::cout << "Error capturing image: " << e.what() << std::endl;
    }

    emit finished();
    //vc->release();
    delete vc;
}


//    try {
//        QThread* thread = new QThread;
//        streamConnector* c = new streamConnector(vc, IP);

//        c->moveToThread(thread);

//        connect(thread, SIGNAL(started()), c, SLOT(process()));
//        connect(c, SIGNAL(finished()), thread, SLOT(quit()));
//        connect(c, SIGNAL(finished()), c, SLOT(deleteLater()));
//        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
//        qDebug() << "attempting to connect";
//        thread->start();
//        thread->wait(1000); // wait some time for connection to establish.
//    } catch(std::exception &e) {
//        std::cout << "Error connecting: " << e.what() << std::endl;
//    }
//    std::cout << "capture: " << vc.isOpened() << std::endl;


//void frameGetter::process()
//{
//    std::cout << "entered framegetter process" << std::endl;

//    streaming = true;
//	// while on - capture images.
//    try {
//        while(streaming)
//        {
//            //std::cout << "streaming" << std::endl;
//            this->msleep(20);
//            if(cv) {
//                // capture from IP camera using openCV
//                if(vc.isOpened()) {
//                    if(!vc.read(frame)) {
//                        std::cout << "Could not get an image from IP camera" << std::endl;
//                    } else {
//                        //imshow("frame", frame);
//                        //waitKey(5);
//                        //emit procFrame(frame); // process this image
//                        qFrame = convertFrame(frame);
//                        emit frameReady(qFrame);
//                        //this->msleep(5);
//                    }
//                } else {
//                    streaming = false;
//                    qDebug() << "streaming off because capture not open";
//                }

//            } else {
//                // Stupid stupid flycam

//            }


//        }
//        destroyAllWindows();
//        if(vc.isOpened()) {
//            //vc.release();
//        }
//    } catch(std::exception &e) {
//        std::cout << "Error capturing an image" << std::endl;
//    }

//    //emit finished();
//}

void frameGetter::endStream()
{
	streaming = false;
}

bool frameGetter::openFlyCam() {
//    FlyCapture2::Error error;
//    //                Camera camera;
//    CameraInfo camInfo;

//    // Connect the camera
//    error = camera.Connect( 0 );
//    if ( error != PGRERROR_OK )
//    {
//        std::cout << "Failed to connect to camera" << std::endl;
//        return false;
//    }


//    // Get the camera info and print it out
//    error = camera.GetCameraInfo( &camInfo );
//    if ( error != PGRERROR_OK )
//    {
//        std::cout << "Failed to get camera info from camera" << std::endl;
//        //return false;
//    }
//    std::cout << camInfo.vendorName << " "
//              << camInfo.modelName << " "
//              << camInfo.serialNumber << std::endl;

//    error = camera.StartCapture();
//    if ( error == PGRERROR_ISOCH_BANDWIDTH_EXCEEDED )
//    {
//        std::cout << "Bandwidth exceeded" << std::endl;
//        return false;
//    }
//    else if ( error != PGRERROR_OK )
//    {
//        std::cout << "Failed to start image capture" << std::endl;
//        return false;
//    }
//    return true;
    return false;
}

void frameGetter::msleep(int ms)
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
