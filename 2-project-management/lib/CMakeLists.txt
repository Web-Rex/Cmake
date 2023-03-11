project(calc)

add_library(${PROJECT_NAME} 
    ./calc/include/calc.h
    ./calc/src/calc.cpp
)

target_include_directories(${PROJECT_NAME} 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/calc/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/calc/src
)

message("")
message("--" ${CMAKE_CURRENT_SOURCE_DIR})
message("")

if(BUILD_TEST)

    message("------- Building Test")
    file(GLOB_RECURSE TEXT_RESOURCE CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp")

    message("")
    foreach(ex_file IN LISTS TEXT_RESOURCE)
    get_filename_component(name_only ${ex_file} NAME_WE) # Name with out Extension
    # [ ]
    add_executable(${name_only} ${ex_file})
    target_link_libraries(${name_only} PUBLIC ${PROJECT_NAME})

    message(STATUS ${name_only})
    # message(STATUS ${ex_file})
    endforeach()
    message("")

endif()