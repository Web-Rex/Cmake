project(Include)

add_library(${PROJECT_NAME} INTERFACE)

# raylib
# set(BUILD_EXAMPLES FALSE CACHE BOOL "x" FORCE) # [ CASHE BOOL "x" FORCE ] to force this variable in cashe
# add_subdirectory(./raylib)
# target_link_libraries(${PROJECT_NAME} INTERFACE raylib)

# opengl
find_package(OpenGL REQUIRED) # [ REQUIRED ] if opengl not found cmake will not build this project
target_link_libraries(${PROJECT_NAME} INTERFACE ${OPENGL_LIBRARIES})

# glad
# add_subdirectory(./glad)
# target_link_libraries(${PROJECT_NAME} INTERFACE Glad)

# glfw Cmake-3.11
include(FetchContent)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "x" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "x" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "x" FORCE)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.3.8
)
FetchContent_MakeAvailable(glfw) # Cmake-3.14
target_link_libraries(${PROJECT_NAME} INTERFACE glfw)

# glew
add_subdirectory(./glew)
target_link_libraries(${PROJECT_NAME} INTERFACE Glew)