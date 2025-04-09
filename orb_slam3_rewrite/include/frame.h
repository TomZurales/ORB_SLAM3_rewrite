#pragma once

#include "camera.h"
#include "keypoint.h"

#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>

// Creates a Frame from an image and the camera which took the image
class Frame
{
private:
  std::vector<cv::KeyPoint> keypoints;
  cv::Mat descriptors;
  Camera camera;
  cv::Mat image;

public:
  Frame(cv::Mat image, Camera camera);

  std::vector<cv::KeyPoint> getKeypoints() { return keypoints; }
  cv::Mat getDescriptors() { return descriptors; }
  cv::Mat getImage() { return image; }
};