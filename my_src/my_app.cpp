#include "my_app.hpp"


namespace my {
MyApp::MyApp() {}

MyApp::~MyApp() {}



void MyApp::run() {
  while (!myWindow.shouleClose()) {
    glfwPollEvents();
  }
}
}  // namespace my