#include "my_app.hpp"

// std
#include <cstdlib>
#include <iostream>
#include <stdexcept>
using namespace my;

int main() {
  MyApp app{};

  try {
    app.run();
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}