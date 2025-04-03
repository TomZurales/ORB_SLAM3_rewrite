#pragma once

#include <Eigen/Core>
#include <opencv2/core.hpp>

// The coordinates of an ORB feature, and its descriptor
class Keypoint
{
private:
  // Undistorted, rectified, and normalized image coordinates of the keypoint in the form [u, v, 1]
  cv::KeyPoint keypoint;
  cv::Mat descriptor;

public:
  Keypoint(cv::KeyPoint keypoint, cv::Mat descriptor) : keypoint(keypoint), descriptor(descriptor) {};
};