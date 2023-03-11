project(Glew LANGUAGES C)


add_library(${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/Release/x64/glew32.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/Release/x64/glew32s.lib
)

target_include_directories(${PROJECT_NAME} 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include 
    # PRIVATE ./src
)