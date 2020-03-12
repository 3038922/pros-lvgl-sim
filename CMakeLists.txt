#设置最低的编译版本
cmake_minimum_required(VERSION 3.10)
#项目名称
project(pros_lvgl_sim)
#设置c/c++标准
set(CMAKE_C_STANDARD 11)#C11
set(CMAKE_CXX_STANDARD 17)#C17
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (AS_A_SUBPROJECT 1)#设置成1 迫使后续模块使用静态库形式导入
set (MAKE_LVGL_DRIVE_STATIC_LIB OFF)# OFF正常编译 ON生成静态库
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build) #设置二进制文件存放路径 
#头文件路径
include_directories(
    ${TOOLCHAIN_INC_DIR} 
    "./include"
    "./include/ncrapi_lvgl_sim_kernel"
    "./include/ncrapi_lvgl_sim_kernel/freeRTOS/src"
)
#关闭警告
add_compile_options(-Wno-unused-private-field -Wno-unused-variable)
#添加需要链接的库文件目录 新建好了 链接的时候用
LINK_DIRECTORIES(
"./include/ncrapi_lvgl_sim_kernel/lib"
"C:/Program Files (x86)/Windows Kits/10/Lib/10.0.18362.0/um/x64" 
"C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.24.28314/lib/x64"
"C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.24.28314/atlmfc/lib/x64"
"C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Auxiliary/VS/lib/x64"
"C:/Program Files (x86)/Windows Kits/10/lib/10.0.18362.0/ucrt/x64"
"C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Auxiliary/VS/UnitTest/lib"
"C:/Program Files (x86)/Windows Kits/NETFXSDK/4.7.2/lib/um/x64")

#######################加入freeRTOS模块#########################
add_subdirectory ("include/ncrapi_lvgl_sim_kernel/freeRTOS")
set (EXTRA_LIBS ${EXTRA_LIBS} freeRTOS)
############################################################################

#######################加入ncrapi_lvgl_sim_kernel模块#########################
add_subdirectory ("include/ncrapi_lvgl_sim_kernel")
set (EXTRA_LIBS ${EXTRA_LIBS} ncrapi_lvgl_sim_kernel)

############################################################################

if(NOT MAKE_LVGL_DRIVE_STATIC_LIB)
    #枚举本地源文件
    file(GLOB_RECURSE SOURCES "src/*.c" "src/*.cpp")
    #生成可执行文件
    add_executable(main ${SOURCES})
    if(CMAKE_HOST_SYSTEM_NAME STREQUAL Linux)
        message(STATUS "linux")
        #寻找sdl2
        find_package(SDL2 REQUIRED SDL2)
        include_directories(${SDL2_INCLUDE_DIRS})
        target_link_libraries(main PRIVATE SDL2 lvgl_gcc drivers_gcc pthread ${EXTRA_LIBS})#不链接pthread easylog编译报错
    elseif(CMAKE_HOST_SYSTEM_NAME STREQUAL Windows)
        message(STATUS "windows")
        #添加-D
        add_definitions(-D_CRT_SECURE_NO_WARNINGS)
        target_link_libraries(main PRIVATE SDL2 SDL2main lvgl_clang_win drivers_clang_win  ${EXTRA_LIBS})#不链接pthread easylog编译报错
    else()
        message(STATUS "无法判断属于哪种系统!")
    endif()
    #添加一个run命令
    add_custom_target (run COMMAND ninja all  COMMAND ${EXECUTABLE_OUTPUT_PATH}/main)
else()

endif()







