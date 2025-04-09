#include "slam_sensor.h"
#include "utility.h"

SlamSensor::SlamSensor(std::shared_ptr<Camera> camera)
{
  cameras.push_back(camera);
}

SlamSensor::SlamSensor(std::shared_ptr<Camera> camera1, std::shared_ptr<Camera> camera2, float baseline)
{
  cameras.push_back(camera1);
  cameras.push_back(camera2);
  this->baseline = baseline;

  cv::Mat r1, r2, p1, p2, q;
  cv::stereoRectify(
      cameras[0]->getIntrinsics(), cameras[0]->getDistortion(),
      cameras[1]->getIntrinsics(), cameras[1]->getDistortion(),
      cv::Size(752, 480), cv::Matx33d::eye(), cv::Matx31d(0, 0.11, 0),
      r1, r2, p1, p2, q);

  cv::Mat map1, map2;
  cv::initUndistortRectifyMap(camera1->getIntrinsics(), camera1->getDistortion(), r1, p1, cv::Size(752, 480), CV_32F, map1, map2);

  camera1->setUndistortRectifyMaps(map1, map2);

  cv::Mat map21, map22;
  cv::initUndistortRectifyMap(camera2->getIntrinsics(), camera2->getDistortion(), r2, p2, cv::Size(752, 480), CV_32F, map21, map22);

  camera2->setUndistortRectifyMaps(map1, map2);
}

SensorData SlamSensor::getSensorData()
{
  cv::Mat left = cv::imread("/home/tom/workspace/thesis/slam_systems/ORB_SLAM3_rewrite/orb_slam3_rewrite/test/data/left.png");
  cv::Mat right = cv::imread("/home/tom/workspace/thesis/slam_systems/ORB_SLAM3_rewrite/orb_slam3_rewrite/test/data/right.png");

  return SensorData(left, cameras[0], right, cameras[1]);
}