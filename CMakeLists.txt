cmake_minimum_required(VERSION 3.16.3)

project(ctests)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)

find_package(Threads REQUIRED)

set(CMAKE_CXX_COMPILER gcc)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)
add_compile_definitions(TESTS)

include(GNUInstallDirs)

include_directories(
    arrays 
    argv_parse
    defines 
    fun_pointers 
    functions 
    recursion1 
    std_lib_object     
    strings 
    structs
    files
    deps/console-colors
    bitwise
    hashes
    c_arg_parse
    types
    pthread
    )

#add_subdirectory(arrays)


add_executable(ctests  
    deps/console-colors/console-colors.c
    arrays/array_func.c
    bitwise/bitwise.c
    c_arg_parse/arg_parse.c
    argv_parse/arg_parse_config.c
    fun_pointers/func_pointers.c
    functions/different_functions.c
    main/main.c
    hashes/hash_calc.c
    files/files.c
    recursion1/recur.c
    std_lib_object/std_lib_object.c
    strings/str_change.c
    strings/str_functions.c
    structs/structs.c
    types/c_types.c
    pthread/pthread_test.c
    )
    
#target_include_directories(ctests 
#    $(CMAKE_CURRENT_LIST_DIR))

target_link_libraries(ctests -Wall -Wextra ${CMAKE_THREAD_LIBS_INIT})
 

