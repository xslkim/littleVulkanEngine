#pragma once
#include "window.hpp"
#include "MyPipeline.hpp"
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
  MyPipeline myPipline{"shaders/my_simple_shader.vert.spv", "shaders/my_simple_shader.frag.spv"};
};
}

