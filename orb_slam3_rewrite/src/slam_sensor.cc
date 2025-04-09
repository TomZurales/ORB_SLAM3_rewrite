#include "slam_sensor.h"
#include "utility.h"

SlamSensor::SlamSensor(Camera camera)
{
  cameras.push_back(camera);
}

SlamSensor::SlamSensor(Camera camera1, Camera camera2, float baseline)
{
  cameras.push_back(camera1);
  cameras.push_back(camera2);
  this->baseline = baseline;

  cv::Mat r1, r2, p1, p2, q;
  cv::stereoRectify(
      cameras[0].getIntrinsics(), cameras[0].getDistortion(),
      cameras[1].getIntrinsics(), cameras[1].getDistortion(),
      cv::Size(752, 480), cv::Matx33f::eye(), cv::Matx31f(0, 0.11, 0),
      r1, r2, p1, p2, q);

  // printMat(r1);
  // printMat(r2);
  // printMat(p1);
  // printMat(p2);
}

SensorData SlamSensor::getSensorData()
{
  cv::Mat left = cv::imread("/home/tom/workspace/Thesis/slam_systems/ORB_SLAM3_rewrite/orb_slam3_rewrite/test/data/left.png");
  cv::Mat right = cv::imread("/home/tom/workspace/Thesis/slam_systems/ORB_SLAM3_rewrite/orb_slam3_rewrite/test/data/right.png");

  return SensorData(left, cameras[0], right, cameras[1]);
}