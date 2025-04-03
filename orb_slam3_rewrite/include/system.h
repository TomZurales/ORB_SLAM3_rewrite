#pragma once

#include <memory>

#include "slam_sensor/base.h"
#include "slam_sensor/slam_data.h"

class System
{
private:
    std::shared_ptr<Base> sensor;

public:
    void setSensor(std::shared_ptr<Base> sensor) { this->sensor = sensor; }

    void run();
};
