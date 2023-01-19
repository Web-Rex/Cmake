# CMakeList.txt : CMake project for src, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (${CMAKE_PROJECT_NAME} "main.cpp" "main.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
