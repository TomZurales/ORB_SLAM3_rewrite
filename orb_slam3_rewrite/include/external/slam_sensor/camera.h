#pragma once

#include "keypoint.h"

#include <vector>
#include <Eigen/Core>
#include <opencv2/features2d.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/core.hpp>

class Camera
{
    Eigen::Matrix3d intrinsics;
    std::vector<double> distortion_coeffeicents;

public:
    Keypoint undistortKeypoint(Keypoint keypoint);

    // TODO: Remove, testing only
    void setIntrinsics(Eigen::Matrix3d intrinsics) { this->intrinsics = intrinsics; }
    void setDistortion(std::vector<double> distortion_coeffeicents) { this->distortion_coeffeicents = distortion_coeffeicents; }
};