#pragma once

#include <opencv4/opencv2/core.hpp>
#include <vector>

class SlamData
{
private:
    cv::Mat image_left;
    cv::Mat image_right;
    std::vector<std::vector<double>> imu_readings;
};