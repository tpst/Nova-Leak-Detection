#include "test.h"
#include <iostream>

test::test()
{
    try {
        vc.open("/home/zzaj/Videos/Nova Leak Videos/Latest/1.asf");
    } catch(std::exception &e) {
        qDebug() << e.what();
    }
    (vc.isOpened()) ? on=true : on = false;
    std::cout << "File opened: " << on << std::endl;
}

test::~test()
{
    on = false;
}

void test::msleep(int ms)
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

void test::process() {
    std::cout << "test.process: " << on << std::endl;
    while(on) {
        this->msleep(12);
        vc.read(frame);
        if(frame.rows <= 0) {
           // vc.open("/home/zzaj/Videos/Nova Leak Videos/Latest/1.asf");

            vc.set(CV_CAP_PROP_POS_AVI_RATIO, 0);
            continue;
        } else {
            //imshow("frame", frame);
            cv::waitKey(5);
            emit procFrame(frame);
        }
    }
}
