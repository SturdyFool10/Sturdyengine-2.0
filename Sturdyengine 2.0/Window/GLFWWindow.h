#pragma once
#include "glfw/glfw3.h"
#include "glm/common.hpp"
#include "Renderer/VulkanRenderer.h"
#include <string>
#include <vector>
#include <iostream>
namespace SFT {
	namespace Window {
		//using these to make the code more readable
		using namespace glm;
		using std::string;
		using std::vector;

		class Window {
		private:
			GLFWwindow* window;
#ifdef GRAPHICS_API_VULKAN_ENABLE
			SFT::Renderer::Renderer* renderer;
#endif
		public:
#ifdef GRAPHICS_API_VULKAN_ENABLE
			Window(int x, int y, string title, SFT::Renderer::VulkanRenderer& render) {
				this->renderer = &render;
#else
			Window(int x, int y, string title) {
#endif
				//create the window
				//setup glfw for vulkan
				glfwInit();
#ifdef GRAPHICS_API_VULKAN_ENABLE
				glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
				glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
#endif
				this->window = glfwCreateWindow(x, y, title.c_str(), NULL, NULL);
				if (this->window == NULL) {
#ifdef _DEBUG
					std::cout << "Failed to create GLFW window" << std::endl;
#endif
					glfwTerminate();
					exit(EXIT_FAILURE);
				}
			}
			//we will now need to index the monitors on the system
			//this is a function that will return a list of monitors
		};
	}
}