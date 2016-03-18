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
	qDebug() << "initializing streaming..";

	if(isStopped()) //if streaming is stopped - turn on
		stop = false;

	start(); // call run method. 
}

void captureHandler::run() 
{
    if(init) {
        get2 = new frameGetter(CV);
        get1 = new frameGetter(false);

        thread1 = new QThread;

        connect(thread1, SIGNAL(started()), get1, SLOT(process()));
        connect(get1, SIGNAL(frameReady(QImage)), this, SIGNAL(frameReady(QImage)));
        connect(this, SIGNAL(streamOver()), get1, SLOT(endStream()));
        //connect(get1, SIGNAL(finished()), thread1, SLOT(quit()));
        //connect(get1, SIGNAL(finished()), get1, SLOT(deleteLater()));
        connect(get1, SIGNAL(refreshDisplays()), this, SIGNAL(refreshDisplays()));
        connect(this, SIGNAL(finished()), get1, SLOT(deleteLater()));
        connect(this, SIGNAL(finished()), thread1, SLOT(quit()));
        connect(thread1, SIGNAL(finished()), thread1, SLOT(deleteLater()));
        connect(this, SIGNAL(streamOver()), get1, SLOT(endStream()));

        get1->moveToThread(thread1);
        //thread1->start();

        // 2nd capture object
        thread2 = new QThread;
        //connect(this, SIGNAL(startStream()), get2, SLOT(process()));
        connect(thread2, SIGNAL(started()), get2, SLOT(process()));
        connect(get2, SIGNAL(frameReady(QImage)), this, SIGNAL(frameReady2(QImage)));
        connect(this, SIGNAL(streamOver()), get2, SLOT(endStream()));
        //connect(get2, SIGNAL(finished()), thread2, SLOT(quit()));
        //connect(get2, SIGNAL(finished()), get2, SLOT(deleteLater()));
        connect(get2, SIGNAL(refreshDisplays()), this, SIGNAL(refreshDisplays()));
        connect(this, SIGNAL(finished()), get2, SLOT(deleteLater()));
        connect(this, SIGNAL(finished()), thread2, SLOT(quit()));
        connect(thread2, SIGNAL(finished()), thread2, SLOT(deleteLater()));

        //get2->moveToThread(thread2);
        thread2->start();

        thread2->quit();

        //init = false;
    }

	try {
		if(stream1Active) {
			stream1Active = get1->openFlyCam();
		}
        stream1Active ? qDebug() << "Connected s1" : qDebug() << "s1 could not connect";

	} catch(std::exception &e) {
		qDebug() << "Error connecting to stream 1";
		stream1Active = false;
	}
	try {
        if(stream2Active && init) {
			stream2Active = get2->newConnection(IP1);
            stream2Active ? qDebug() << "Connected s2" : qDebug() <<"s2 could not connect";
            init = false;
		}
	} catch(std::exception &e) {
		qDebug() << "Error connecting to stream 2";
		stream2Active = false;
	}
    std::cout << this << std::endl;
    std::cout << get2 << std::endl;
    get2->moveToThread(thread2);
    thread2->start();
    std::cout << "thread2 is: " << thread2->isRunning() << std::endl;

    std::cout << "emitting" << std::endl;
    std::cout << stop << std::endl;
	emit refreshDisplays();
    emit startStream();


	while(!stop) {
		// capture video while 1 or more streams are connected or until stop is pressed
        if(!stream1Active && !stream2Active) {
			stop = true;
        }
        //std::cout << stream1Active << ", " << stream2Active << std::endl;
        get2->msleep(20);

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
    get2->endStream();
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
