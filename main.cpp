#include "GLFW/glfw3.h"
#include "webgpu/webgpu_cpp.h"

import std;

int main() {
  std::cout << "Hello, World!" << std::endl;

  glfwInit();

  // Create the window
  GLFWwindow *window = glfwCreateWindow(640, 480, "Learn WebGPU", NULL, NULL);

  // 1. We create a descriptor
  WGPUInstanceDescriptor desc = {};
  desc.nextInChain = nullptr;

  // 2. We create the instance using this descriptor
  WGPUInstance instance = wgpuCreateInstance(&desc);

  // 3. We can check whether there is actually an instance created
  if (!instance) {
    std::cerr << "Could not initialize WebGPU!" << std::endl;
    return 1;
  }

  // 4. Display the object (WGPUInstance is a simple pointer, it may be
  // copied around without worrying about its size).
  std::cout << "WGPU instance: " << instance << std::endl;

  while (!glfwWindowShouldClose(window)) {
    // Check whether the user clicked on the close button (and any other
    // mouse/key event, which we don't use so far)
    glfwPollEvents();
  }

  // At the end of the program, destroy the window
  glfwDestroyWindow(window);

  glfwTerminate();

  return 0;
}
