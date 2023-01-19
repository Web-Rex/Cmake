# CMakeList.txt : CMake project for src, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (${CMAKE_PROJECT_NAME} "main.cpp" "main.h")

# We created one target (that will build an executable) using the source files.
# Then, we provide the definitions needed by that target using the target_compile_definitions.
# There are other methods to the compiler calls like add_definitions but they are discouraged. Why?
# Using target_compile_definitions we will apply the definitions just to the desired targets and add_definitions will ad them to all the targets.
# [ PRIVATE, INTERFACE, PUBLIC ] keyword references to the visibility of the definition

# [ PUBLIC ] it is the union between the INTERFACE and PRIVATE vibilities
# [ PRIVATE ] used when the definitions will be applied just for the current target.
# [ INTERFACE ] used when the definitions need to be applied to targets that link against the given target.

target_compile_definitions(${CMAKE_PROJECT_NAME}
    PRIVATE
        AWESOME
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
