// Sturdyengine 2.0.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
//use precompiler statements to select the graphics api, have linux and windows use the same api for now
#ifdef _WIN32
	#define GRAPHICS_API_VULKAN_ENABLE
#else
	#ifdef __linux__
		#define GRAPHICS_API_VULKAN_ENABLE
	#endif
#endif




// TODO: Reference additional headers your program requires here.
#ifdef _DEBUG
using std::cout;
#endif
#include <string>
#include "Renderer/Renderer.h"
#include "Window/GLFWwindow.h"
#include "glm/common.hpp"
//now for the meat and potatoes
namespace SFT {
		class SturdyEngine {
		private:
			SFT::Window::Window window;
			SFT::Renderer::Renderer renderer;
		public:
			SturdyEngine(glm::tvec2<int> winSize, std::string windowTitle) {
				window = SFT::Window::Window(glm::tvec2<int>(winSize.x, winSize.y), windowTitle);
			}
			~SturdyEngine() {
				
			}
			void Setup() {

			}
			void Update() {

			}

		};
	}