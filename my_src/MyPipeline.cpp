#include "MyPipeline.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>

namespace my {
MyPipeline::MyPipeline(
    MyDevice& device,
    const std::string& vertFilepath,
    const std::string& fragFilepath,
    const PipelineConfigInfo& configInfo)
    : myDevice(device) {
  createGraphicsPipeline(vertFilepath, fragFilepath, configInfo);
}

void MyPipeline::createGraphicsPipeline(
    const std::string& vertFilepath,
    const std::string& fragFilepath,
    const PipelineConfigInfo& configInfo) {
  auto vertCode = readFile(vertFilepath);
  auto fragCode = readFile(fragFilepath);
  std::cout << "vertCodeSize:" << vertCode.size();
  std::cout << "fragCodeSize:" << fragCode.size();
}

void MyPipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule) {
  VkShaderModuleCreateInfo createInfo{};
  createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
  createInfo.codeSize = code.size();
  createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());
  if (vkCreateShaderModule(myDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS) {
    throw std::runtime_error("failed to create shader module");
  }
}

std::vector<char> MyPipeline::readFile(const std::string& filepath) {
  std::ifstream file(filepath, std::ios::ate | std::ios::binary);
  if (!file.is_open()) {
    throw std::runtime_error("faile to openfile:" + filepath);
  }
  size_t fileSize = static_cast<size_t>(file.tellg());
  std::vector<char> buffer(fileSize);
  file.seekg(0);
  file.read(buffer.data(), fileSize);
  file.close();
  return buffer;
}

PipelineConfigInfo MyPipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height) {
  PipelineConfigInfo info = {};
  return info;
}

}  // namespace my
