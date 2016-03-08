#include "frameprocessor.h"

using namespace cv;

frameProcessor::frameProcessor()
{

}

frameProcessor::~frameProcessor()
{

}

void frameProcessor::process(Mat frame)
{
    // image processing goes here

    imshow("window1", frame);

    //emit frameReady(qFrame);
    //emit finished();
}
