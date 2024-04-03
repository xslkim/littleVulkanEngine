#pragma once
#include "window.hpp"
namespace my
{

class MyApp {
 public:
  MyApp();
  ~MyApp();
  bool shouleClose();
  void run();

  static constexpr int WIDTH = 800;
  static constexpr int HEIGHT = 600;

 private:
  Window myWindow{WIDTH, HEIGHT, "myWindow"};
};
}

