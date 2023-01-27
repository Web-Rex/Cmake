# CMakeList.txt : CMake project for src, include source and define
# project specific logic here.
#

# Add source to this project's executable.

function (building_library_with_target)
	# [ add_executable (${CMAKE_PROJECT_NAME} "main.cpp" "main.h" "lib/math/math.cpp" "lib/math/math.h") ]
	set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

	set(SOURCES main.cpp lib/math/math.cpp lib/math/math.h)
	add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
endfunction()

function (building_library_separate_than_target share lib_path)
	# shared library require you to export all of the symbolls so u get a .lib file out of the .dll file 
	# so you use this to make it posible [ set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) ]
	print("Library Path: ${lib_path}")

	if(${share} MATCHES true)
		print("share: ${share}")
		add_library(math SHARED ${lib_path})
	else(${share} MATCHES false)
		print("share: ${share}")
		add_library(math STATIC ${lib_path})
	endif()


	add_executable(${CMAKE_PROJECT_NAME} main.cpp)
	target_link_libraries(${CMAKE_PROJECT_NAME} math)
endfunction()

function (build_library_as_sub_module_cmake)

	add_executable(${CMAKE_PROJECT_NAME} main.cpp)
	target_link_libraries(${CMAKE_PROJECT_NAME} convert)

endfunction()

build_library_as_sub_module_cmake()

target_compile_definitions( ${CMAKE_PROJECT_NAME}
PRIVATE
	OUT_LIB=${out_lib}
)

add_dependencies(${CMAKE_PROJECT_NAME} my_custom_target) # needed to make your [ add_custom_target ] work cause its [ BUILD ALL ] not [ BUILD ONE ]


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
