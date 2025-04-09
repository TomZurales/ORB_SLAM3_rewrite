#include "utility.h"

cv::Mat vectorToMat(const std::vector<std::vector<float>> &vec)
{
  // Get the number of rows and columns
  int rows = vec.size();
  int cols = rows > 0 ? vec[0].size() : 0;

  // Create a cv::Mat with the same dimensions
  cv::Mat mat(rows, cols, CV_32F);

  // Copy data from the vector of vectors into the cv::Mat
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      mat.at<float>(i, j) = vec[i][j];
    }
  }

  return mat;
}

// void triangulateMapPointsFromStereoFrames()

void printMat(const cv::Mat &mat)
{
  for (int i = 0; i < mat.rows; ++i)
  {
    for (int j = 0; j < mat.cols; ++j)
    {
      std::cout << mat.at<float>(i, j) << " ";
    }
    std::cout << std::endl;
  }
}

void depthFromStereoPair(Frame leftImage, Frame rightImage, double baseline)
{
  // Compute matches between left and right images
  cv::BFMatcher matcher(cv::NORM_HAMMING);
  std::vector<std::vector<cv::DMatch>> matches;
  matcher.knnMatch(leftImage.getDescriptors(), rightImage.getDescriptors(), matches, 2);

  // Lowe's Method for eliminating overly-similar matches
  std::vector<cv::DMatch> goodMatches;
  for (auto match : matches)
  {
    if (match[0].distance < (0.75 * match[1].distance))
    {
      goodMatches.push_back(match[0]);
    }
  }

  // Now we need to get depths. To do this, we need the
}
