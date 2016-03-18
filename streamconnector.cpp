#include "streamconnector.h"
#include <iostream>

streamConnector::streamConnector(cv::VideoCapture &capture, QString addr)
{
    address = addr;
    cap = &capture;
}

streamConnector::~streamConnector()
{

}

// Attempts to open connection with IP camera stream
void streamConnector::process()
{
    try {
        std::cout << " connecting: " << cap->isOpened() << std::endl;
        if(!cap->isOpened())
        {
            qDebug() << "Opening " + address;
            std::cout << address.toStdString() << std::endl;

            if(address == "http://.../mjpg/video.mjpg") {
                cap->open(0); // open default webcam
            } else {
                cap->open(address.toStdString());
            }

        }


    } catch(std::exception &e) {
        qDebug() << "Stream could not connect. Returned error: " << e.what();
    }

//    cv::Mat frame;
//    cap->read(frame);
//    imshow("frame", frame);

//    qDebug() << "asdsad" << cap->isOpened();
//    cv::waitKey(0);
    //emit finished();
}
