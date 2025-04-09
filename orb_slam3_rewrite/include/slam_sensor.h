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

  SensorData(cv::Mat left, Camera leftCam, cv::Mat right, Camera rightCam) : left_frame(Frame(left, leftCam)), right_frame(Frame(right, rightCam)) {}
};

/*!
TODO: Convert to pure virtual and create implementations for different cameras
*/
class SlamSensor
{
  std::vector<Camera> cameras;
  float baseline;

public:
  // Constructor for the monocular case
  SlamSensor(Camera camera);

  // Constructor for the stereo case
  SlamSensor(Camera camera1, Camera camera2, float baseline);

  SensorData getSensorData();
};