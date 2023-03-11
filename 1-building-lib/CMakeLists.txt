cmake_minimum_required(VERSION 3.17)


project("building-lib")


add_subdirectory("${CMAKE_SOURCE_DIR}/print")
add_subdirectory("${CMAKE_SOURCE_DIR}/calc")
add_subdirectory("${CMAKE_SOURCE_DIR}/src")