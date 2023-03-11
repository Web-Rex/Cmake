project(Lib)

# [ ]
add_library(${PROJECT_NAME} 
            ./include/calc.h
            ./src/calc.cpp
)
target_include_directories(${PROJECT_NAME}  
        PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/include 
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_link_libraries(${PROJECT_NAME}  PRIVATE prv_lib)