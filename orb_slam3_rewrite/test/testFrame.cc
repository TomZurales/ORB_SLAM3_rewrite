#include "frame.h"
#include "camera.h"
#include "slam_sensor.h"

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include "utility.h"

int main(int argc, char **argv)
{
  std::shared_ptr<Camera> cam1(new Camera());
  cv::Mat cam1_matrix = (cv::Mat_<double>(3, 3) << 458.654, 0, 367.215, 0, 457.296, 248.375, 0, 0, 1);
  cam1->setIntrinsics(cam1_matrix);
  double cam1_distortions[] = {-0.28340811, 0.07395907, 0.00019359, 1.76187114e-05};
  cam1->setDistortion(cv::Mat(1, 4, CV_64F, cam1_distortions));

  std::shared_ptr<Camera> cam2(new Camera);
  cv::Mat cam2_matrix = (cv::Mat_<double>(3, 3) << 457.587, 0, 379.999, 0, 456.134, 255.238, 0, 0, 1);
  cam2->setIntrinsics(cam2_matrix);
  double cam2_distortions[] = {-0.28368365, 0.07451284, -0.00010473, -3.55590700e-05};
  cam2->setDistortion(cv::Mat(1, 4, CV_64F, cam2_distortions));

  SlamSensor sensor(cam1, cam2, 0.11);
  SensorData data = sensor.getSensorData();

  depthFromStereoPair(data.left_frame, data.right_frame, 0.11);

  return 0;
}