#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace my
{
class Window {
 public:
  Window(int w, int h, std::string name);
  ~Window();
  bool shouleClose();
  void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

 private:
  void initWindow();
  const int width;
  const int height;
  const std::string windowName;
  GLFWwindow* window;
};
}

