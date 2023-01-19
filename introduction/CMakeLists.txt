# CMake is a framework to build/test/package software. It is not a build system: it is a build system generator.
# CMake is an extensible, open-source system that manages the build process in an operating system and in a compiler-independent manner.
# CMake as a Scripting Language.
# CMake intended to be a cross-platform build process manager so it defines it is own scripting language with certain syntax and built-in features.
cmake_minimum_required (VERSION 3.8)

project ("Introduction")

# Some commonly used commands
# [ cmake_minimum_required (VERSION 3.8) ] - sets minimum version of cmake to be used
# [ add_executable ] - adds executable target with given name
# [ add_library ] - adds a library target to be build from listed source files
# [ add_subdirectory ] - adds a subdirectory to build

# There are also commands to enable developers write out conditional statements, loops, iterate on list, assignments:
# [ if, endif ]
# [ elif, endif ]
# [ while, endwhile ]
# [ foreach, endforeach ]
# [ list ]
# [ function ]
# [ return ]
# [ set_property ] - assign value to variable.

# Indentation is not mandatory but suggested while writing CMake scripts. CMake doesn’t use ‘;’ to understand end of statement.
# All conditional statements should be ended with its corresponding end command (endif, endwhile, endforeachetc)
# Environment variables are used to configure compiler flags, linker flags, test configurations for a regular build process. Compiler have to be guided to search for given directories for libraries.
# [ set(CMAKE_CXX_FLAGS "-Wall") ] - append flag, best practice, suggested, don't lose previously defined flags

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_STANDARD 14)


set(TRIAL_VARIABLE "VALUE")
set(files a.txt b.txt c.txt)
set (my_list "A B C")
set(boolean "null")
string (REPLACE " " ";" my_list "${my_list}")
set(var true)
set(foo A B C)
set(bar 2 3 4)
set(foo_bar 1 a 2 b 3 c 4 d)
set(fooBar 1 " 2A" 3 "4B " 5 6C)

if(${boolean})
    message("boolean if--- ${boolean}")
elseif(${boolean} MATCHES "null")
    message("boolean elseif--- ${boolean}")
else()
    message("boolean else--- ${boolean}")
endif()
foreach(file ${files})
    message("Filename--- ${file}")
endforeach()
foreach (my_entry IN LISTS my_list)

    set(_my_other_list "A" "B" "C")
    
    # All done! do something with ${my_entry}, for example:
    if (NOT my_entry IN_LIST _my_other_list)
        message(FATAL_ERROR "_my_list has ${my_entry} but _my_other_list does not!!")
    endif()
endforeach()
function (do_the_thing HAS_PROPERTY_A)

    if (HAS_PROPERTY_A)
        message(STATUS "Early Return")
        set(var false PARENT_SCOPE)
        return()
    endif()

    message(STATUS "Later Return")
endfunction()
do_the_thing(TRUE)
do_the_thing(FALSE)

list(APPEND foo D)
list(PREPEND bar 1)
list(APPEND foobar ${foo} ${bar})

list(POP_BACK foobar four three)
list(POP_FRONT foobar a b)
list(INSERT foobar 2 ${four} ${a} ${three} ${b})

# Index-based operations
list(LENGTH foo_bar foobar_len)
list(FIND foo_bar 2 index_2)
list(SUBLIST foo_bar ${index_2} 4 middle)
list(GET foo_bar 1 3 5 7 alpha)
list(REMOVE_AT foo_bar 1 3 5 7)

# Mutating operations
list(TRANSFORM fooBar STRIP)        # remove whitespace
list(TRANSFORM fooBar TOLOWER)      # to lower case
list(TRANSFORM fooBar REPLACE "([0-9])([a-z])" "\\2\\1\\2" REGEX "[0-9][a-z]")

# Iteration

message("--------------------------------------------------------------------------")
message("")

message("Output---" ${CMAKE_CURRENT_SOURCE_DIR}) # Path to src dir. [ relative path ]
message("CXX standard--- ${CMAKE_CXX_STANDARD}") # Get version of c++ bing used in your project
message("Cmake binary dir--- ${CMAKE_BINARY_DIR}") # Full path to top level of build tree and binary output folder, by default it is defined as top level of build tree.
message("Cmake home dir--- ${CMAKE_HOME_DIRECTORY}") # Path to top of source tree
message("Cmake src dir--- ${CMAKE_SOURCE_DIR}") # Full path to top level of source tree.
message("Cmake include path--- ${CMAKE_INCLUDE_PATH}") # Path used to find file, path
message("TRIAL_VARIABLE--- ${TRIAL_VARIABLE}") # Get data in [ TRIAL_VARIABLE ] variable
message("var--- ${var}") # Get data in [ var ] variable
message("foo--- ${foo}") # Get data in [ foo ] variable
message("bar--- ${bar}") # Get data in [ bar ] variable
message("foobar--- ${foobar}") # Get data in [ foobar ] variable
message("foo_bar--- ${foobar}") # Get data in [ foo_bar ] variable
message("fooBar--- ${foobar}") # Get data in [ fooBar ] variable

message("")
message("--------------------------------------------------------------------------")

# Include sub-projects.
add_subdirectory ("${CMAKE_CURRENT_SOURCE_DIR}/src")