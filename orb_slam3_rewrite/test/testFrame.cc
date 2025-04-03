#include "frame.h"
#include "slam_sensor/camera.h"

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

int main(int argc, char **argv)
{
  // Load an image
  cv::Mat image_left = cv::imread("/home/tom/workspace/thesis/slam_systems/ORB_SLAM3_rewrite/orb_slam3_rewrite/test/data/left.png");

  Camera cam;
  cam.setIntrinsics(Eigen::Matrix3d(458.654, 0, 367.215, 0, 457.296, 248.375, 0, 0, 1));
  cam.setDistortion({-0.28340811, 0.07395907, 0.00019359, 1.76187114e-05});
  Frame f(image_left, cam);

  cv::imshow("Initial Image", image_left);
  cv::waitKey(0);
  return 0;
}