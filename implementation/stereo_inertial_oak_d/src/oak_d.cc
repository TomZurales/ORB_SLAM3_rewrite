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

  // Create our left and right valid pixel masks
  auto calibrationHandler = device->readCalibration();
  auto leftIntrinsics = calibrationHandler.getCameraIntrinsics(dai::CameraBoardSocket::CAM_B);
  auto rightIntrinsics = calibrationHandler.getCameraIntrinsics(dai::CameraBoardSocket::CAM_C);
  auto distortions = calibrationHandler.getDistortionCoefficients auto leftExtrinsics = calibrationHandler.getCameraToImuExtrinsics() auto leftRectification = calibrationHandler.getStereoLeftRectificationRotation();
  auto rightRectification = calibrationHandler.getStereoRightRectificationRotation();

  auto leftFrame = leftQueue->get<dai::ImgFrame>();

  cv::Mat leftMap1, leftMap2, rightMap1, rightMap2;
  cv::Size imageSize(leftFrame->getWidth(), leftFrame->getHeight());
  cv::initUndistortRectifyMap(
      vectorToMat(leftIntrinsics), cv::Mat(), vectorToMat(leftRectification),
      vectorToMat(leftIntrinsics), imageSize, CV_32FC1, leftMap1, leftMap2);

  cv::initUndistortRectifyMap(
      vectorToMat(leftIntrinsics), cv::Mat(), cv::Mat(rightRectification),
      vectorToMat(leftIntrinsics), imageSize, CV_32FC1, rightMap1, rightMap2);

  cv::Mat rectificationMask = cv::Mat::zeros(imageSize, CV_8UC1);
  for (int y = 0; y < imageSize.height; ++y)
  {
    for (int x = 0; x < imageSize.width; ++x)
    {
      cv::Point2f pt = leftMap1.at<cv::Point2f>(y, x);
      if (pt.x >= 0 && pt.x < imageSize.width && pt.y >= 0 && pt.y < imageSize.height)
      {
        rectificationMask.at<uchar>(y, x) = 255;
      }
    }
  }

  cv::imshow("Rectification Mask", rectificationMask);
  cv::waitKey(0);
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