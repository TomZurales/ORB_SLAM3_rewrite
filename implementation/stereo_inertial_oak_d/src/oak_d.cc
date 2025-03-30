#include "slam_sensor/oak_d.h"

OakD::OakD()
{
  HAS_IMU = true;
  HAS_STEREO_CAMERA = true;

  // Create our pipeline
  pipeline = dai::Pipeline();
  auto leftCam = pipeline.create<dai::node::MonoCamera>();
  leftCam->setCamera("left");
  auto rightCam = pipeline.create<dai::node::MonoCamera>();
  rightCam->setCamera("right");
  auto stereoDepth = pipeline.create<dai::node::StereoDepth>();
  stereoDepth->setLeftRightCheck(true);
  leftCam->out.link(stereoDepth->left);
  rightCam->out.link(stereoDepth->right);

  auto leftXOut = pipeline.create<dai::node::XLinkOut>();
  auto rightXOut = pipeline.create<dai::node::XLinkOut>();
  leftXOut->setStreamName("rectified_left");
  rightXOut->setStreamName("rectified_right");

  stereoDepth->rectifiedLeft.link(leftXOut->input);
  stereoDepth->rectifiedRight.link(rightXOut->input);

  device = std::shared_ptr<dai::Device>(new dai::Device(pipeline));

  leftQueue = device->getOutputQueue("rectified_left", 1, false);
  rightQueue = device->getOutputQueue("rectified_right", 1, false);
}

SlamData OakD::getFrame()
{
  // Get the latest frames
  auto leftFrame = leftQueue->get<dai::ImgFrame>();
  auto rightFrame = rightQueue->get<dai::ImgFrame>();

  // Convert to OpenCV format
  cv::Mat leftMat = cv::Mat(leftFrame->getHeight(), leftFrame->getWidth(), CV_8UC1, leftFrame->getData().data());
  cv::Mat rightMat = cv::Mat(rightFrame->getHeight(), rightFrame->getWidth(), CV_8UC1, rightFrame->getData().data());

  SlamData data;
  data.setImageLeft(leftMat);
  data.setImageRight(rightMat);
  return data;
}