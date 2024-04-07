#include "MyPipeline.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>

namespace my {
MyPipeline::MyPipeline(
    const MyDevice device,
    const std::string& vertFilepath,
    const std::string& fragFilepath,
    const PipelineConfigInfo& configInfo) {
  createGraphicsPipeline(vertFilepath, fragFilepath);
}

void MyPipeline::createGraphicsPipeline(const std::string vertFilepath, const std::string fragfilepath) {
  auto vertCode = readFile(vertFilepath);
  auto fragCode = readFile(fragfilepath);
  std::cout << "vertCodeSize:" << vertCode.size();
  std::cout << "fragCodeSize:" << fragCode.size();
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
}

