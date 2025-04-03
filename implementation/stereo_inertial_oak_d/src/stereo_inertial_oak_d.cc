#include "system.h"

#include "slam_sensor/oak_d.h"

int main(int argc, char **argv)
{
    System system;
    system.setSensor(std::shared_ptr<Base>(new OakD()));

    system.run();

    return 0;
}