#include "capturehandler.h"
#include "streamconnector.h"
#include "frameprocessor.h"

#include <QApplication>

// constructor
captureHandler::captureHandler(QObject* parent) : QThread(parent), on(false)
{
    stop = true;
    record = false;
    processActive = false;

    proc = new frameProcessor(on);
    connected = false;
    qRegisterMetaType< variables >("variables");
    connect(this, SIGNAL(applySettings(variables)), proc, SLOT(copyVariables(variables)));

    thread3 = new QThread;
    proc->moveToThread(thread3);
    thread3->start();
}

captureHandler::~captureHandler()
{
    quit();
    wait();
}

// initialises up to 2 streams
void captureHandler::playStream()
{
    // attempt to connect
    // validate connection / return error
    // update display

    qDebug() << "Initializing streaming...";

    if(isStopped())
        stop = false;

    start();
}

bool captureHandler::newConnection(cv::VideoCapture &capture, QString address)
{
    QThread* thread = new QThread;
    streamConnector* c = new streamConnector(capture, address);

    c->moveToThread(thread);

    connect(thread, SIGNAL(started()), c, SLOT(process()));
    connect(c, SIGNAL(finished()), thread, SLOT(quit()));
    connect(c, SIGNAL(finished()), c, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
    thread->wait(5000); // wait some time for connection to establish.

    if(capture.isOpened()) {
        return true;
    } else {
        return false;
    }
}

void captureHandler::run()
{
    try {
        if(stream1Active) {
            //vc.open(0);
            stream1Active = openFlyCam();
            if(stream1Active)
                qDebug() << "Stream 1 Connected";
        }
    } catch (std::exception & e) {
        qDebug() << "Failed to open stream 1";
        stream1Active = false;
    }

    try {
        if(!vc2.isOpened() && stream2Active) {
            // new connection thread
            stream2Active = newConnection(vc2, IP1);
            if(!stream2Active)
                qDebug() << "Failed to open stream 2";
        }
    } catch (std::exception &e) {
        qDebug() << "Failed to open stream 2";
        stream2Active = false;
    }
    emit refreshDisplays();

    thread1 = new QThread;
    thread2 = new QThread;
    //thread3 = new QThread;

    if(stream1Active) {

        //thread1 = new QThread;
//        get1 = new frameGetter(camera);

//        connect(thread1, SIGNAL(started()), get1, SLOT(process()));

//        connect(get1, SIGNAL(frameReady(QImage)), this, SIGNAL(frameReady(QImage)));

//        connect(get1, SIGNAL(finished()), thread1, SLOT(quit()));

//        connect(get1, SIGNAL(finished()), get1, SLOT(deleteLater()));

//        connect(thread1, SIGNAL(finished()), thread1, SLOT(deleteLater()));

//        connect(this, SIGNAL(streamOver()), get1, SLOT(endStream()));

//        connect(get1, SIGNAL(refreshDisplays()), this, SIGNAL(refreshDisplays()));

//        get1->moveToThread(thread1);

//        thread1->start();
    }

    if(stream2Active) {
        //thread2 = new QThread;

        get2 = new frameGetter(vc2);

        connect(thread2, SIGNAL(started()), get2, SLOT(process()));

        connect(get2, SIGNAL(frameReady(QImage)), this, SIGNAL(frameReady2(QImage)));

        connect(get2, SIGNAL(finished()), thread2, SLOT(quit()));

        connect(get2, SIGNAL(finished()), get2, SLOT(deleteLater()));

        connect(thread2, SIGNAL(finished()), thread2, SLOT(deleteLater()));

        connect(get2, SIGNAL(refreshDisplays()), this, SIGNAL(refreshDisplays()));

        get2->moveToThread(thread2);

        thread2->start();


    }

    //bool on = false; // logic for image processing stream
    //frameProcessor* proc;

    // Main process loop for capturing video
    while(!stop)
    {
        // do some stuff i guess
        if(processActive && stream2Active) {
            if(!on) {
                // processor is off - initialise new one.
                on = true;
                if(!connected) {
                    connect(get2, SIGNAL(procFrame(cv::Mat)), proc, SLOT(process(cv::Mat)));

                    connect(proc, SIGNAL(frameReady(QImage)), this, SIGNAL(frameReady2(QImage)));

                    connect(proc, SIGNAL(finished()), thread3, SLOT(quit()));

                    connect(proc, SIGNAL(finished()), proc, SLOT(deleteLater()));

                    connect(get2, SIGNAL(finished()), proc, SIGNAL(finished()));

                    connect(thread3, SIGNAL(finished()), thread3, SLOT(deleteLater()));
                    connected = true;
                }

                //connect(this, SIGNAL(applySettings(variables)), proc, SLOT(copyVariables(variables)));

            }
        } else {
            on = false;
        }
        if(!stream1Active && !stream2Active)
            stop = true;
    }

}

bool captureHandler::openFlyCam() {
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
}

//void captureHandler::recordStream()
//{
//    // record some stuff
//}

void captureHandler::Stop()
{
    emit streamOver();

    record = false;
    stop = true;
    std::cout << "RELEASING CAMERA?" << std::endl;
    //vc.release();
    vc2.release();
    //camera.Disconnect();

    qDebug() << "Streaming halted.";

    this->quit();
    this->wait();

}

void captureHandler::msleep(int ms)
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

void captureHandler::toggleStream1(bool value)
{
    stream1Active = value;
}

void captureHandler::toggleStream2(bool value)
{
    stream2Active = value;
}

bool captureHandler::isStream1Active()
{
    return stream1Active;
}

bool captureHandler::isStream2Active()
{
    return stream2Active;
}

void captureHandler::toggleProcess(bool value)
{
    processActive = value;
}

bool captureHandler::isProcessActive()
{
    return processActive;
}

bool captureHandler::isStopped()
{
    return stop;
}

bool captureHandler::isRecording()
{
    return record;
}

void captureHandler::toggleRecord(bool value)
{
    record = value;
}

