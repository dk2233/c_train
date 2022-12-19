cmake_minimum_required(VERSION 3.16.3)

project(ctests)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_COMPILER gcc)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

include(GNUInstallDirs)

include_directories(
    arrays 
    defines 
    fun_pointers 
    functions 
    recursion1 
    std_lib_object     
    strings 
    structs
    files
    )

#add_subdirectory(arrays)


add_executable(ctests  
    arrays/array_func.c
    fun_pointers/func_pointers.c
    functions/different_functions.c
    main/main.c
    files/files.c
    recursion1/recur.c
    std_lib_object/std_lib_object.c
    strings/str_change.c
    structs/structs.c)
    
#target_include_directories(ctests 
#    $(CMAKE_CURRENT_LIST_DIR))

target_link_libraries(ctests -Wall)

