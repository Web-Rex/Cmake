# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

set(shared true)
set(library_path "${CMAKE_SOURCE_DIR}/src/lib/math/math.cpp")

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

# Shared vs Static Library
# Shared Library File Extensions: [ Windows: .dll ] [ Mac OS X: .dylib ] [ Linux: .so ]
# Static Library File Extensions: [ Windows: .lib ] [ Mac OS X: .a ] [ Linux: .a ]

# Shared libraries are mainly placed in a shared resource of host to make sure multiple applications can access them. [ Shared libraries are mainly placed in a shared resource of host to make sure multiple applications can access them. ]
# Static libraries are used to fetch instructions directly into application binary by compiler, so all the code required from library are already injected into final application binary. [ That increase the size of object but increase the size of binary but performance get increased. ]


# Include sub-projects.
add_subdirectory ("${CMAKE_SOURCE_DIR}/src")
