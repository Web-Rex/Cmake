project(main)

add_executable(${PROJECT_NAME} ./main.cpp ./main.h)

# [ Compiler Flags ]
include(CheckCXXCompilerFlag) # include to use.

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    CHECK_CXX_COMPILER_FLAG(/02 FLAG_IS_OK)

    if(FLAG_IS_OK)
        target_compile_options(${PROJECT_NAME} PRIVATE /02)
    endif()
    
endif()
# [ Linker Flags ]
# include(CheckLinkerFlag)
# target_link_options()


# [ Multiple Configure Project ] -- Run cmake configuration once - vscode project u are able to use choose multiple option for compilation
# [ Single Configure Project ] -- Configuration cmake seperatly for e.g Debug, Release, 32bit, Operating system

# [ Single Configuration ]
# if(CMAKE_BUILD_TYPE) -- Since Cmake is a cross platform tool, You should not limit your script to work for only linux
# endif()

# [ generator Expresion ] -- This tool generate a project for cmake -- So there is a generator for [ Make-Filse ] [ Visuai-Studio ]
# [ $<> ] [ $<IF: Condition, If-True, If-False> ]
set(MY_BUILD_TYPE $<IF:$<CONFIG:Debug>, 1, 0>)

target_compile_definitions(${PROJECT_NAME}
    # PRIVATE MY_DEBUG -- define but no value set
    PRIVATE MY_DEBUG = ${MY_BUILD_TYPE} # define but value set
)