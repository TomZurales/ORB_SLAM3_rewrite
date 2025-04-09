#pragma once

#include "keypoint.h"

#include <vector>
#include <Eigen/Core>
#include <opencv2/features2d.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/core.hpp>

class Camera
{
  cv::Mat intrinsics;
  cv::Mat distortion_coeffeicents;

  cv::Mat map1, map2;

public:
  std::vector<cv::KeyPoint> undistortKeypoints(std::vector<cv::KeyPoint> keypoints);

  // TODO: Remove, testing only
  void setIntrinsics(cv::Mat intrinsics) { this->intrinsics = intrinsics; }
  cv::Mat getIntrinsics() { return intrinsics; }

  void setDistortion(cv::Mat distortion_coeffeicents) { this->distortion_coeffeicents = distortion_coeffeicents; }
  cv::Mat getDistortion() { return distortion_coeffeicents; }

  void setUndistortRectifyMaps(cv::Mat map1, cv::Mat map2)
  {
    this->map1 = map1;
    this->map2 = map2;
  }
};