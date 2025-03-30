#pragma once

#include "slam_data.h"

namespace SlamSensor
{
    class Base
    {
    protected:
        bool HAS_IMU;
        bool HAS_STEREO_CAMERA;

    public:
        bool hasIMU() { return HAS_IMU; }
        bool hasStereoCamera() { return HAS_STEREO_CAMERA; }

        SlamData getFrame();
    };
}