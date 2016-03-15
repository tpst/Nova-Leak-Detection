#include "test.h"

test::test()
{
    vc.open("/home/zzaj/Videos/Nova Leak Videos/Latest/1.asf");
    on = true;
}

test::~test()
{
    on = false;
}

void test::msleep(int ms)
{
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
}

void test::process() {

    while(on) {
        this->msleep(15);

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
