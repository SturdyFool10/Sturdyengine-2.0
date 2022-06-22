# CMakeList.txt : CMake project for Sturdyengine 2.0, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (CMakeTarget "Sturdyengine 2.0.cpp" "Sturdyengine 2.0.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
#add_subdirectory ("./Input")
#add_subdirectory ("./Renderer")
#add_subdirectory ("./Shaders")
#add_subdirectory ("./Sound")
#add_subdirectory ("./Window")

#Add source files to the executable.
target_sources(${TARGET} "./SturdyEngine 2.0.h")