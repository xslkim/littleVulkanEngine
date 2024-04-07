#pragma once
#include "my_device.hpp"

#include <string>
#include <vector>


namespace my {
struct PipelineConfigInfo {};

class MyPipeline {
 public:
  MyPipeline(
      const MyDevice device,
      const std::string& vertFilepath,
      const std::string& fragFilepath,
      const PipelineConfigInfo& configInfo);

 private:
  static std::vector<char> readFile(const std::string& filepath);
  void createGraphicsPipeline(const std::string vertFilepath, const std::string fragfilepath);
  MyDevice& myDevice;
  VkPipeline graphicsPipeline;
};
}

