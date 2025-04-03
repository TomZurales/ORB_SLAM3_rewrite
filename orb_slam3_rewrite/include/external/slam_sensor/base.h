#pragma once

#include "slam_data.h"

class Base
{
protected:
    int NUM_CAMERAS;
    bool HAS_IMU;

    // transform_camera_to_base[i] is the SE3 transformation between camera[i] and the base frame.
    // In a stereo pair, without an IMU, transform_camera_to_base[0] will most likely be the identity matrix, making camera[0] the base frame.
    // With an IMU, transform_camera_to_base[i] will most likely be set to the transform between camera[i] and the IMU frame.
    std::vector<Sophus::SE3f> transform_camera_to_base;

public:
    Base(int num_cameras, bool has_imu) : NUM_CAMERAS(num_cameras),
                                          HAS_IMU(has_imu)
    {
    }

    bool hasIMU() { return HAS_IMU; }
    // bool hasStereoCamera() { return HAS_STEREO_CAMERA; }

    virtual SlamData getFrame() = 0;
    virtual ~Base() = default;
};