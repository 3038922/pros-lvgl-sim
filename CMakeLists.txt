#设置最低的编译版本
cmake_minimum_required(VERSION 3.10)
#项目名称
project(pros_lvgl_sim)
#设置c/c++标准
set(CMAKE_C_STANDARD 11)#C11
set(CMAKE_CXX_STANDARD 17)#C17
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-variable -Wno-unused-function -Wunused-private-field")
#头文件路径
include_directories(
    ${TOOLCHAIN_INC_DIR} 
    "./include"
)
set(MODE 1)# 1正常编译 2生成静态库

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) #设置二进制文件存放路径 
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/firmware) #设置各种库存放路径
if(MODE EQUAL 1)
    #枚举头文件
    file(GLOB_RECURSE INCLUDES "include/*.h" "include/*.hpp")
    #枚举源文件
    file(GLOB_RECURSE SOURCES "include/lv_examples/*.c" "src/*.c" "src/*.cpp")
    #添加需要链接的库文件目录 新建好了 链接的时候用
    LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})
    #生成可执行文件
    add_executable(main ${SOURCES} ${INCLUDES})
    #链接SDL2的静态库
    if(CMAKE_HOST_SYSTEM_NAME STREQUAL Linux)
        message(STATUS "linux")
        #寻找sdl2
        find_package(SDL2 REQUIRED SDL2)
        include_directories(${SDL2_INCLUDE_DIRS})
        target_link_libraries(main PRIVATE SDL2 lvgl_gcc drivers_gcc pthread)#不链接pthread easylog编译报错
    elseif(CMAKE_HOST_SYSTEM_NAME STREQUAL Windows)
        message(STATUS "windows")
        #添加-D
        add_definitions(-D_CRT_SECURE_NO_WARNINGS)
        target_link_libraries(main PRIVATE SDL2 SDL2main lvgl_clang_win drivers_clang_win)#不链接pthread easylog编译报错
    else()
        message(STATUS "无法判断属于哪种系统!")
    endif()
    #添加一个run命令
    add_custom_target (run COMMAND ninja all  COMMAND ${EXECUTABLE_OUTPUT_PATH}/main)
else() 
    #要建立的静态库
    file(GLOB_RECURSE LIBLVGL "include/lvgl/*.c")
    file(GLOB_RECURSE LIBDRIVERS "include/lv_drivers/*.c")
    message(STATUS "LIBLVGL_PATH:${LIBLVGL}")
    message(STATUS "LIBDRIVERS_PATH:${LIBDRIVERS}")
    #file(GLOB_RECURSE LIBRESOURCES "./src/system/logo.c" "./src/system/field.c")
    if(CMAKE_HOST_SYSTEM_NAME STREQUAL Linux)
        message(STATUS "linux")
        #寻找sdl2
        find_package(SDL2 REQUIRED SDL2)
        include_directories(${SDL2_INCLUDE_DIRS})
        add_library(lvgl_gcc STATIC ${LIBLVGL})
        add_library(drivers_gcc STATIC ${LIBDRIVERS})
        #add_library(resources STATIC ${LIBRESOURCES}_linux)
    elseif(CMAKE_HOST_SYSTEM_NAME STREQUAL Windows)
        message(STATUS "windows")
        #添加-D
        add_definitions(-D_CRT_SECURE_NO_WARNINGS)
        add_library(lvgl_clang_win STATIC ${LIBLVGL})
        add_library(drivers_clang_win STATIC ${LIBDRIVERS})
        #add_library(resources STATIC ${LIBRESOURCES}_win)
    else()
        message(STATUS "无法判断属于哪种系统!")
    endif()
endif()








