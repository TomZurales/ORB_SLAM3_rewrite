#include "slam_sensor/oak_d.h"

int main(int argc, char **argv)
{
    OakD sensor;
    sensor.getFrame();
    cv::waitKey();
    return 0;
}