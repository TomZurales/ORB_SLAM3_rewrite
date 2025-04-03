#pragma once

#include "slam_sensor/base.h"
#include "depthai/depthai.hpp"
#include "utility.h"

class OakD : public Base
{
private:
  dai::Pipeline pipeline;
  std::shared_ptr<dai::Device> device;

  std::shared_ptr<dai::DataOutputQueue> leftQueue;
  std::shared_ptr<dai::DataOutputQueue> rightQueue;

public:
  OakD();
  SlamData getFrame() override;
};