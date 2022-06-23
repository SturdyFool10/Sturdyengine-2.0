// Sturdyengine 2.0.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
//use precompiler statements to select the graphics api, have linux and windows use the same api for now
#define UseVK
#ifdef _WIN32
	#ifdef UseVK
		#define GRAPHICS_API_VULKAN_ENABLE
	#else
		#ifdef UseOpenGL
			#define	NORT
			#define NODLSS
			#define NOFSR
			#define NOMESHSHADERS
			#define GRAPHICS_API_OPEN_GL_ENABLE
		#elseif
			#define GRAPHICS_API_DIRECTX_ENABLE
		#endif	
	#endif
#else
	//we will likely not support macos because who the fuck games on macos, like, buy a real pc for that
	#ifdef __linux__
		//if UseOpenGL is defined, change from vk to gl
		#ifdef UseOpenGL
			#define GRAPHICS_API_OPEL_GL_ENABLE
		#else
			#define GRAPHICS_API_VULKAN_ENABLE
		#endif	
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