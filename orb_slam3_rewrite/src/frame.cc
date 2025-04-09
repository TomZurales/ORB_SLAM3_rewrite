#include "frame.h"

Frame::Frame(cv::Mat image, std::shared_ptr<Camera> camera) : camera(camera), image(image)
{
  auto orb_extractor = cv::ORB::create();

  // Outputs buffers for the ORB extraction
  std::vector<cv::KeyPoint> cv_keypoints;

  // Perform the ORB extraction
  orb_extractor->detectAndCompute(image, cv::Mat(), cv_keypoints, descriptors);
  keypoints = camera->undistortKeypoints(cv_keypoints);
}