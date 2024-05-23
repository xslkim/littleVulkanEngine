#pragma once
#include <string>
#include <vector>

#include "my_device.hpp"

namespace my {
struct PipelineConfigInfo {};

class MyPipeline {
 public:
  MyPipeline(
      MyDevice& device,
      const std::string& vertFilepath,
      const std::string& fragFilepath,
      const PipelineConfigInfo& configInfo);
  ~MyPipeline(){}
  MyPipeline(const MyPipeline&) = delete;
  void operator=(const MyPipeline&) = delete;
  static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

 private:
  static std::vector<char> readFile(const std::string& filepath);
  void createGraphicsPipeline(
      const std::string& vertFilepath,
      const std::string& fragFilepath,
      const PipelineConfigInfo& configInfo);
  void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule); 
  MyDevice& myDevice;
  VkPipeline graphicsPipeline;
  VkShaderModule vertShaderModule;
  VkShaderModule fragShaderModule;
};
}  // namespace my
