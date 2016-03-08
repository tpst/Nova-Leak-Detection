#include "streamconnector.h"

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
        if(!cap->isOpened())
        {
            qDebug() << "Opening " + address;

            if(address == "http://0.../mjpg/video.mjpg") {
                cap->open(0); // open default webcam
            } else {
                cap->open(address.toStdString());
            }

        }

    } catch(std::exception &e) {
        qDebug() << "Stream could not connect. Returned error: " << e.what();
    }

    emit finished();
}
