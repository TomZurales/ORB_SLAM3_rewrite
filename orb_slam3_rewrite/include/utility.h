#pragma once

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <vector>
#include <iostream>

#include "frame.h"

cv::Mat vectorToMat(const std::vector<std::vector<float>> &vec);
void printMat(const cv::Mat &mat);

void depthFromStereoPair(Frame leftImage, Frame rightImage, double baseline);