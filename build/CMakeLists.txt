# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("build")
set(CMAKE_CXX_STANDARD 20)
# Let’s edit our CMakeLists.txt to generate binary file inside bin folder with setting CMAKE_RUNTIME_OUTPUT_DIRECTORY or EXECUTABLE_OUTPUT_PATH.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# [ CMAKE_SYSTEM ]  - the complete system name
# [ CMAKE_SYSTEM_NAME ] - The name of the system targeted by the build. The three common values are Windows, Darwin, and Linux, though several others exist, such as Android, FreeBSD, and CrayLinuxEnvironment. Platforms without an operating system, such as embedded devices, are given Generic as a system name.
# [ CMAKE_SYSTEM_VERSION ] - Version of the operating system. Generally the kernel version.
# [ CMAKE_SYSTEM_PROCESSOR ] - the processor name (e.g. "Intel(R) Pentium(R) M processor 2.00GHz")
# [ CMAKE_HOST_SYSTEM_NAME ] - The name of the system hosting the build. Has the same possible values as CMAKE_SYSTEM_NAME.

message("--------------------------------------------------------------------------")
message("")

# UNIX, WIN32, WINRT, CYGWIN, APPLE are environment variables as flags set by default system
if(UNIX)
    message("This is a ${CMAKE_SYSTEM_NAME} system")
elseif(WIN32)
    message("This is a ${CMAKE_SYSTEM_NAME} System")
endif()
# or use MATCHES to see if actual system name 
# Darwin is Apple's system name 
if(${CMAKE_SYSTEM_NAME} MATCHES Darwin)
    message("This is a ${CMAKE_SYSTEM_NAME} system")
elseif(${CMAKE_SYSTEM_NAME} MATCHES Windows)
    message("This is a ${CMAKE_SYSTEM_NAME} System")
endif()

# Macros help engineers to build code conditionally to discard or include certain methods according to running system configurations.
# You can define macros in CMake with add_definitions command, using -D flag before the macro name.
# Cmake definitions

# or use MATCHES to see if actual system name 
# Darwin is Apple's system name
if(${CMAKE_SYSTEM_NAME} MATCHES Darwin)
    add_definitions(-DCMAKEMACRO1="Apple MacOS")
elseif(${CMAKE_SYSTEM_NAME} MATCHES Windows)
    add_definitions(-DCMAKEMACRO1="Windows PC")
endif()

# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
FATAL: In-source builds are not allowed.
       You should create a separate directory for build files.
")
endif()

message("")
message("--------------------------------------------------------------------------")

# Include sub-projects.
add_subdirectory (${CMAKE_SOURCE_DIR}/src)
