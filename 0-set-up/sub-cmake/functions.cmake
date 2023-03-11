# [ Func ]
function(func_var)
    message("variable: ${variable} indept: ${${variable}}")
endfunction()

function(func_math)
    message("new_number: ${new_number}")
    message("my_number: ${my_number}")
endfunction()

function(func_list)
    message("")
    message("my_list: ${my_list} : list_lenght: ${list_lenght}")
    message("")
    message("my_list: ${my_list} : list_index_0: ${list_index_0}")
    message("")
    if(4 IN_LIST my_list)
        message("4 in list : my_list: ${my_list}")
    endif()
endfunction()

function(func_bool)
    if(my_bool_1 MATCHES true AND my_bool_2 MATCHES true)
    message("if-and my_bool_1: ${my_bool_1} : my_bool_2: ${my_bool_2}")
    elseif(my_bool_1 MATCHES false OR my_bool_2 MATCHES false)
    message("else-if-or my_bool_1: ${my_bool_1} : my_bool_2: ${my_bool_2}")
    else()
    message("else my_bool_1: ${my_bool_1} : my_bool_2: ${my_bool_2}")
    endif()
    if(my_bool_3 LESS 10)
    message("< 10 : my_bool_3: ${my_bool_3}")
    endif()
    if(my_bool_3 GREATER 4)
    message("> 4 : my_bool_3: ${my_bool_3}")
    endif()
    if(my_bool_3 EQUAL 5)
    message("= 5 : my_bool_3: ${my_bool_3}")
    endif()
    if(my_bool_3 VERSION_LESS_EQUAL 6)
    message("VERSION_LESS_EQUAL : my_bool_3: ${my_bool_3}")
    endif()
endfunction()

function(func_loop)
    while(index_0 LESS 5)
    message("index_0: ${index_0}")
    math(EXPR index_0 "${index_0} + 1")
    endwhile()
    message("")
    list(LENGTH my_new_list my_new_list_length)
    while(${index_1} LESS ${my_new_list_length})
    list(GET my_new_list ${index_1} current_element)
    message("current_element: ${current_element} : index_1: ${index_1}")
    math(EXPR index_1 "${index_1} + 1")
    endwhile()
    message("")
    foreach(elements IN LISTS my_new_list)
    message("--- list ---     ${elements}")
    endforeach()
    message("")
    foreach(elements IN ITEMS ${my_new_list})
    message("--- items ---     ${elements}")
    endforeach()
endfunction()

function(func_func)
    set(my_var 0)

    function(my_func arg_0 arg_1 arg_3)
        set(new_var_0 "New variable -0")
        set(new_var_1 "New variable -1" PARENT_SCOPE)

        foreach(arg_ IN LISTS ARGV)
            message("The argument is: ${arg_}")
        endforeach()
        message("")
        foreach(arg_ IN LISTS ARGN)
            message("The argument is: ${arg_}")
        endforeach()
    endfunction()

    macro(my_macro)
        set(new_var_2 "New variable -2")
    endmacro()
    

    my_func(${my_var} 1 2 3 4 5 6 7 8 9)
    my_macro()
    message("---------   ${new_var_0}")
    message("---------   ${new_var_1}")
    message("---------   ${new_var_2}")
    
endfunction()

function(func_advanced_func)
    function(log)
        set(options WARNING)
        set(oneValueArgs "TEXT")
        set(multiValueArgs "LIST")

        cmake_parse_arguments(
            LOG
            "${options}"
            "${oneValueArgs}"
            "${multiValueArgs}"
            ${ARGN}
        )

        # if(LOG_WARNING)
        #     message(WARNING ${LOG_TEXT})
        # else()
        #     message(STATUS ${LOG_TEXT})
        # endif()
        message(STATUS ${LOG_WARNING})
        message(STATUS ${LOG_TEXT})
        message(STATUS ${LOG_LIST})
        message(STATUS ${ARGN})
    endfunction()

    log(TEXT " Hello " LIST "Hello-0 " "Hello-1 " WARNING)
    
endfunction()

function(func_cmake_variable)
    message("Output---" ${CMAKE_CURRENT_SOURCE_DIR}) # Path to src dir. [ relative path ]
    message("")
    message("CXX standard--- ${CMAKE_CXX_STANDARD}") # Get version of c++ bing used in your project
    message("")
    message("Cmake binary dir--- ${CMAKE_BINARY_DIR}") # Full path to top level of build tree and binary output folder, by default it is defined as top level of build tree.
    message("")
    message("Cmake home dir--- ${CMAKE_HOME_DIRECTORY}") # Path to top of source tree
    message("")
    message("Cmake src dir--- ${CMAKE_SOURCE_DIR}") # Full path to top level of source tree.
    message("")
    message("Cmake include path--- ${CMAKE_INCLUDE_PATH}") # Path used to find file, path
endfunction()