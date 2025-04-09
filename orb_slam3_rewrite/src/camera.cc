#include "camera.h"
#include "utility.h"

std::vector<cv::KeyPoint> Camera::undistortKeypoints(std::vector<cv::KeyPoint> keypoints)
{
  std::vector<cv::Point2f> points, undistortedPoints;

  // Convert KeyPoints to Point2f
  cv::KeyPoint::convert(keypoints, points);

  // Undistort points (results in normalized coordinates)
  cv::undistortPoints(points, undistortedPoints, intrinsics, distortion_coeffeicents, cv::noArray(), intrinsics);

  // Update KeyPoints with undistorted pixel coordinates
  for (size_t i = 0; i < keypoints.size(); ++i)
  {
    keypoints[i].pt = undistortedPoints[i];
  }

  return keypoints;
}