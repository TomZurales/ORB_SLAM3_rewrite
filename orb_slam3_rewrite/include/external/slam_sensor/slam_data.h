#pragma once

#include "sophus/se3.hpp"

#include <opencv2/core.hpp>
#include <vector>

class SlamData
{
private:
  cv::Mat image_left;
  cv::Mat image_right;
  std::vector<std::vector<double>> imu_readings;

public:
  SlamData() { imu_readings = std::vector<std::vector<double>>(); }
  void setImageLeft(cv::Mat image) { image_left = image; }
  void setImageRight(cv::Mat image) { image_right = image; }
  void addImuReading(std::vector<double> imuReading) { imu_readings.push_back(imuReading); }

  cv::Mat getImageLeft() { return image_left; }
  cv::Mat getImageRight() { return image_right; }
};