#pragma once

#include "frame.h"

#include <vector>
#include <Eigen/Core>
#include <opencv2/highgui.hpp>

#include "camera.h"
#include "slam_sensor.h"

class SensorData
{
public:
  Frame left_frame;
  Frame right_frame;

  SensorData(cv::Mat left, std::shared_ptr<Camera> leftCam, cv::Mat right, std::shared_ptr<Camera> rightCam) : left_frame(Frame(left, leftCam)), right_frame(Frame(right, rightCam)) {}
};

/*!
TODO: Convert to pure virtual and create implementations for different cameras
*/
class SlamSensor
{
  std::vector<std::shared_ptr<Camera>> cameras;
  float baseline;

public:
  // Constructor for the monocular case
  SlamSensor(std::shared_ptr<Camera> camera);

  // Constructor for the stereo case
  SlamSensor(std::shared_ptr<Camera> camera1, std::shared_ptr<Camera> camera2, float baseline);

  SensorData getSensorData();
};