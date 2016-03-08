#ifndef STREAMCONNECTOR_H
#define STREAMCONNECTOR_H

#include <QObject>
#include <QDebug>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>

// Class for establishing connection with video streams in a new thread
class streamConnector : public QObject
{
    Q_OBJECT
public:
    streamConnector(cv::VideoCapture &capture, QString addr);
    ~streamConnector();
public slots:
    void process();
signals:
    void finished();
    void error(QString err);

private:
    // variables
    cv::VideoCapture *cap;
    QString address;
};

#endif // STREAMCONNECTOR_H
