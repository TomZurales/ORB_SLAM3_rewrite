#include "frame.h"

Frame::Frame(cv::Mat image, Camera camera) : camera(camera)
{
  auto orb_extractor = cv::ORB::create();

  // Outputs buffers for the ORB extraction
  std::vector<cv::KeyPoint> cv_keypoints;
  cv::Mat descriptors;

  // Perform the ORB extraction
  orb_extractor->detectAndCompute(image, cv::Mat(), cv_keypoints, descriptors);

  // Undistort the keypoints using the calibrations from the camera
  for (int i = 0; i < cv_keypoints.size(); i++)
  {
    // Create a keypoint with the uv coordinates from the distorted image
    Keypoint distortedKeypoint(cv_keypoints[i], descriptors.row(i));
    keypoints.push_back(camera.undistortKeypoint(distortedKeypoint));
  }
}