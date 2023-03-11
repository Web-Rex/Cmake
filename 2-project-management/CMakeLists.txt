cmake_minimum_required(VERSION 2.17)

project(target)

# [ Cashing ] - cmake cashe options and variable set on the command line
# And it only does this once during the build proccess 
# so if you change the value later on it will not work cause it will allways respect the previous value
# [ Delet Cashe ] so cmake will cashe variabble once during the build proccess again
# [ --fresh ] in version 3.24 of cmke u can execute cmake with this command in command line to force clearing the cache 
# [ -U <globbing-cashe-variable-name> ] in previous version you can run this command to clear only some variable from the cashe
option(BUILD_TEST "Build Test or Not" OFF)

# [ OLD - GLOBAL ]
# add_compile_definitions()
# include_directories()
# add_compile_options()



message("------------- " ${BUILD_TEST})

add_subdirectory(${CMAKE_SOURCE_DIR}/lib)
add_subdirectory(${CMAKE_SOURCE_DIR}/src)