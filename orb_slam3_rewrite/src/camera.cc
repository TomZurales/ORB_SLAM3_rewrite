#include "camera.h"
#include "utility.h"

std::vector<cv::KeyPoint> Camera::undistortKeypoints(std::vector<cv::KeyPoint> keypoints)
{
  std::vector<cv::KeyPoint> undistortedKPs;
  for (const auto keypoint : keypoints)
  {
    cv::KeyPoint copy(keypoint);
    copy.pt = cv::Point2f(map1.at<float>(keypoint.pt), map2.at<float>(keypoint.pt));
    undistortedKPs.push_back(copy);
  }

  return undistortedKPs;
}