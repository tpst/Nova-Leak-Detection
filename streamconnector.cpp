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

            if(address == "0") {
                cap->open(0);
            } else {
                cap->open(address.toStdString());
            }

        }

    } catch(std::exception &e) {
        qDebug() << "Something broke in stream connector process";
    }

    emit finished();
}
