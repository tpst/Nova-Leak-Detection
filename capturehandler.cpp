//new capture handler

#include "streamconnector.h"
#include "frameprocessor.h"
#include "capturehandler.h"

#include <QApplication>

#define CV true

captureHandler::captureHandler(QObject* parent) : QThread(parent), on(false), init(true)
{
    stop = true; // streaming off
	record = false;
	processActive = false;

    proc = new frameProcessor(on); // initialise new frameprocessor for configuration.
	connected = false; // frameprocessor is not connected;

	qRegisterMetaType< variables >("variables");
	connect(this, SIGNAL(applySettings(variables)), proc, SLOT(copyVariables(variables)));

	// create and start new thread for cv processing config. 
	thread3 = new QThread;
	proc->moveToThread(thread3);
	thread3->start();
}

captureHandler::~captureHandler()
{

}

void captureHandler::playStream()
{
	if(isStopped()) //if streaming is stopped - turn on
		stop = false;

    thread1 = new QThread;
    thread2 = new QThread;

    get1 = new frameGetter(false);
    get2 = new frameGetter(CV);

    connect(thread1, SIGNAL(started()), get1, SLOT(process()));
    connect(get1, SIGNAL(frameReady(QImage)), this, SIGNAL(frameReady(QImage)));
    connect(get1, SIGNAL(finished()), thread1, SLOT(quit()));

    connect(thread2, SIGNAL(started()), get2, SLOT(process()));
    connect(get2, SIGNAL(frameReady(QImage)), this, SIGNAL(frameReady2(QImage)));
    connect(get2, SIGNAL(finished()), thread2, SLOT(quit()));

    get1->moveToThread(thread1);
    get2->moveToThread(thread2);


    try {
        if(stream1Active) {
            stream1Active = get1->openFlyCam();
        }
        stream1Active ? std::cout << "Connected s1" : std::cout << "s1 could not connect";
        std::cout << std::endl;
    } catch(std::exception &e) {
        qDebug() << "Error connecting to stream 1";
        stream1Active = false;
    }
    try {
        if(stream2Active) {
            stream2Active = get2->newConnection(IP1);
            stream2Active ? std::cout << "Connected s2" : std::cout <<"s2 could not connect";
            std::cout << std::endl;
            if(stream2Active) {
                emit updateStatus("Stream2 connected");
            } else {
                emit updateStatus("stream 2 did not connect");
            }
        }
    } catch(std::exception &e) {
        qDebug() << "Error connecting to stream 2";
        stream2Active = false;
    }
    emit refreshDisplays();
    // start streaming threads.
    if(stream1Active) {
        thread1->start();
    }
    if(stream2Active) {
        thread2->start();
    }
	start(); // call run method. 
}

void captureHandler::run() 
{
    while(!stop) {
        // capture video while 1 or more streams are connected or until stop is pressed
        if(!stream1Active && !stream2Active) {
            stop = true;
        }
        if(processActive && stream2Active) {
            if(!on) {
                on = true;
                if(!connected) {
                    thread3 = new QThread;
                    proc2 = new frameProcessor(on);
                    connect(get2, SIGNAL(procFrame(cv::Mat)), proc2, SLOT(process(cv::Mat)));
                    // probably disconnect get2 and frameReady
                    connect(proc2, SIGNAL(frameReady(QImage)), this, SIGNAL(frameReady2(Qimage)));
                    connect(proc2, SIGNAL(finished()), thread3, SLOT(quit()));
                    connect(proc2, SIGNAL(finished()), proc2, SLOT(deleteLater()));
                    connect(thread3, SIGNAL(finished()), thread3, SLOT(deleteLater()));
                    // copy variables here.
                    connected = true; // frame processor is connected - dont try to connect again it will break
                }
            }
        } else {
            on = false; // either the stream or process was turned off - toggle off
        }
   }
    std::cout << "HANDLER STOPPING" << std::endl;
}

void captureHandler::endStreams() {
    this->stop = true;
    this->record = false;
    if(stream1Active) get1->endStream();
    if(stream2Active) get2->endStream();
}

void captureHandler::Stop()
{
    //emit streamOver();
    stop = true;
    record = false;

    std::cout << "Ending streams." << std::endl;

    if(stream1Active && !init)
        get1->endStream();
    if(stream2Active && !init) {
        get2->endStream();
    }

    std::cout << "streams ended" << std::endl;
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
