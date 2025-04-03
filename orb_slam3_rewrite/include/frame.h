#pragma once

#include "slam_sensor/camera.h"
#include "keypoint.h"

#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>

// Creates a Frame from an image and the camera which took the image
class Frame
{
private:
  std::vector<Keypoint> keypoints;
  Camera camera;

public:
  Frame(cv::Mat image, Camera camera);
};