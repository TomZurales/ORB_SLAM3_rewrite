#pragma once

#include <opencv4/opencv2/core.hpp>
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
};