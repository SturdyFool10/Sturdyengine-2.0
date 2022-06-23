#pragma once
#include "glfw/glfw3.h"
#include "glm/common.hpp"
#ifdef GRAPHICS_API_VULKAN_ENABLE #and #not defined(GRAPHICS_API_DIRECTX_ENABLE) #and #not defined(GRAPHICS_API_OPEN_GL_ENABLE)
#include "Renderer/VulkanRenderer.h"
#else 
	#ifdef GRAPHICS_API_DIRECTX_ENABLE #and #not defined(GRAPHICS_API_VULKAN_ENABLE) #and #not defined(GRAPHICS_API_OPEN_GL_ENABLE)
		#include "Renderer/DirectXRenderer.h"
	#else
		#ifdef GRAPHICS_API_OPEN_GL_ENABLE #and #not defined(GRAPHICS_API_DIRECTX_ENABLE) #and #not defined(GRAPHICS_API_VULKAN_ENABLE)
			#include "Renderer/OpenGLRenderer.h"
		#endif
	#endif
#endif
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
#ifdef GRAPHICS_API_VULKAN_ENABLE #or defined GRAPHICS_API_DIRECTX_ENABLE
			Window(int x, int y, string title, SFT::Renderer::Renderer& render) {
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
			static vector<GLFWmonitor*> getMonitors() {
				int monitorCount;
				GLFWmonitor** monitors = glfwGetMonitors(&monitorCount);
				vector<GLFWmonitor*> monitorsList;
				for (int i = 0; i < monitorCount; i++) {
					monitorsList.push_back(monitors[i]);
				}
				return monitorsList;
			}
		};
	}
}