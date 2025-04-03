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