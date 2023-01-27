# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
# Shared vs Static Library
# Shared Library File Extensions: [ Windows: .dll ] [ Mac OS X: .dylib ] [ Linux: .so ]
# Static Library File Extensions: [ Windows: .lib ] [ Mac OS X: .a ] [ Linux: .a ]

# Shared libraries are mainly placed in a shared resource of host to make sure multiple applications can access them. [ Shared libraries are mainly placed in a shared resource of host to make sure multiple applications can access them. ]
# Static libraries are used to fetch instructions directly into application binary by compiler, so all the code required from library are already injected into final application binary. [ That increase the size of object but increase the size of binary but performance get increased. ]
cmake_minimum_required (VERSION 3.8)

set(shared true)
set(out_lib 3)

if(${out_lib} MATCHES 1)
	set(library_path "${CMAKE_SOURCE_DIR}/lib/print/print.cpp")
else(${out_lib} MATCHES 2)
	set(library_path "${CMAKE_SOURCE_DIR}/src/lib/math/math.cpp")
endif()

project ("build_library")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

if(${shared} MATCHES true)
	set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
else(${shared} MATCHES false)
	set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
endif()

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

function(print inp)
	message("-------------------------------------------------------------------------")
	message("")
	message(${inp})
	message("")
	message("-------------------------------------------------------------------------")
endfunction()

if(${CMAKE_BUILD_TYPE} MATCHES Debug)
    print("${CMAKE_BUILD_TYPE} Build")
elseif(${CMAKE_BUILD_TYPE} MATCHES Release)
    print("${CMAKE_BUILD_TYPE} Build")
endif()

if(CMAKE_SYSTEM MATCHES Windows)
   print("Target system is Windows")
endif()

if(CMAKE_HOST_SYSTEM MATCHES Linux)
   print("Build host runs Linux")
endif()

# The add_custom_target CMake macro
# this macro "Adds a target with the given name that executes the given commands". So, you can create a CMake target that will execute a command

# The add_custom_command CMake macro
# This defines a command to generate specified OUTPUT file(s). What does it mean? The command will generate some output files only if needed.

add_custom_target(my_custom_target
    COMMAND
        ${CMAKE_COMMAND} -E echo Hi this is a custom target
	DEPENDS
        "${CMAKE_CURRENT_BINARY_DIR}/generated_file"
    VERBATIM
)

# If we call CMake, we will not have a way to call this custom command. Why? Because in CMake we build targets. 
# Since there was not a defined target, the custom command will not be executed. 
# So, we have to create a custom target and create a dependency between our custom target and our custom command:

add_custom_command(
    OUTPUT
        "${CMAKE_CURRENT_BINARY_DIR}/generated_file"
    COMMAND
        ${CMAKE_COMMAND} -E touch ${CMAKE_CURRENT_BINARY_DIR}/generated_file.txt
	DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp # We can improve the process. Imagine that we need to call this command only if something changed in the source code. We need to add this file to the DEPENDS argument of add_custom_command:
)

# Include sub-projects.
add_subdirectory("${CMAKE_SOURCE_DIR}/lib/convert")
add_subdirectory ("${CMAKE_SOURCE_DIR}/src")