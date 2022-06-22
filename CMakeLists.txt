# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Sturdyengine 2.0")

# Include sub-projects.
include_directories("Sturdyengine 2.0/" "Sturdyengine 2.0/Libraries/glfw/include/" "Sturdyengine 2.0/Libraries/glm/" "Sturdyengine 2.0/Libraries/Vulkan/Include/")
add_executable("SturdyEngineTest" "./Test Files/main.cpp")