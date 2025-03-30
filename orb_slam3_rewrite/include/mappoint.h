#pragma once

#include "hidden/descriptor.h"
#include <sophus/se3.hpp>

class MapPoint
{
private:
    Descriptor descriptor;
    Sophus::SE3d pose;
};