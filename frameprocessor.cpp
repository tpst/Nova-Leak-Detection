#include "frameprocessor.h"

using namespace cv;

frameProcessor::frameProcessor(bool &on)
{
    run = &on;
}

frameProcessor::~frameProcessor()
{
    // free resources
}

void frameProcessor::process(Mat frame)
{
    // image processing goes here
    if(*run) {
        try {
            imshow("window1", frame);
        } catch(std::exception &e) {
            qDebug() << "Image processing failed";
        }
    } else {
        destroyAllWindows();
        emit finished();
    }
}
