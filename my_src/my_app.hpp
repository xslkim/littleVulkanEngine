#pragma once
#include "window.hpp"
#include "MyPipeline.hpp"
#include "my_device.hpp"
namespace my
{

class MyApp {
 public:
  MyApp();
  ~MyApp();
  void run();

  static constexpr int WIDTH = 800;
  static constexpr int HEIGHT = 600;

 private:
  Window myWindow{WIDTH, HEIGHT, "myWindow"};
  MyDevice myDevice{myWindow};
  MyPipeline myPipline{
      myDevice,
      "shaders/my_simple_shader.vert.spv",
      "shaders/my_simple_shader.frag.spv",
      MyPipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
};
}

