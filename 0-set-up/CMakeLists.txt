cmake_minimum_required(VERSION 3.17)
project("set-up")

# [ Var ]
set(pizza "Pepperoni")
set(variable "pizza")
set(index_0 0)
set(index_1 0)
# [ Math ]
set(my_number 5)
math(EXPR new_number "${my_number} + 3")
# [ List ]
set(my_list 5 4 3 2 1)
set(my_new_list 1 2 3 4 5 6 7 8 9)
list(LENGTH my_list list_lenght)
list(GET my_list 0 list_index_0)
list(APPEND my_list 9)
list(PREPEND my_list 6)
list(POP_FRONT my_list)
# [ Bool ]
set(my_bool_1 true) # true, false, on, of, yes, no, y, n, 1, 0, 1, 0, ignore, notfound
set(my_bool_2 true)
set(my_bool_3 5)

include("${CMAKE_SOURCE_DIR}/sub-cmake/functions.cmake")

# [ Execute ]
message("-------------------------")
message("-----")

# [ Var ]
#func_var()

# [ Math ]
#func_math()

# [ List ]
#func_list()

# [ Bool ]
#func_bool()

# [ Loops ]
#func_loop()

# [ func ]
#func_func()
# func_advanced_func()

# [ cmake variable ]
func_cmake_variable()

message("-----")
message("-------------------------")

add_executable(${CMAKE_PROJECT_NAME} "./main.cpp" "./main.h")