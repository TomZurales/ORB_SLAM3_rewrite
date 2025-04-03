#include "system.h"

#include <opencv2/highgui.hpp>
#include <opencv2/features2d.hpp>

void System::run()
{
  while (true)
  {
    SlamData data = sensor->getFrame();

    // Extract ORB features from the left frame
    auto orb_extractor = cv::ORB::create();
    std::vector<cv::KeyPoint> keypoints;
    cv::Mat descriptors;
    orb_extractor->detectAndCompute(data.getImageLeft(), cv::Mat(), keypoints, descriptors);

    cv::imshow("Left Image", data.getImageLeft());
    cv::Mat leftWithKeypoints;
    cv::drawKeypoints(data.getImageLeft(), keypoints, leftWithKeypoints);
    cv::imshow("Left Image With Keypoints", leftWithKeypoints);

    if (cv::waitKey(1) >= 0)
      break;
  }
}