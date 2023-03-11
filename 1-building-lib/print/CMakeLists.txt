project(prv_lib)

# [ automatically grab all the required specified library from the specified folder ]
# This reads all header not source cause all header file with out configing because header files are not compiled directly
# [ CMAKE_CONFIGURE_DEPENDS ] it will configure project everytime you build - [ SLOW ]
file(GLOB_RECURSE HEADERS CMAKE_CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE SOURCES CMAKE_CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

message("")
message(STATUS ${HEADERS})
message(STATUS ${SOURCES})
message("")

# [ ]
add_library(${PROJECT_NAME} 
            ${HEADERS} 
            ${SOURCES}
)
target_include_directories(${PROJECT_NAME} 
            PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/include
            PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

