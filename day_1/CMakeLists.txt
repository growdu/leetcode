# 声明一个 cmake 工程
project(Demo)
# 声明要求的 cmake 最低版本
cmake_minimum_required( VERSION 3.14 )
set(CMAKE_C_COMPILER "gcc")
# 设置编译模式
set( CMAKE_BUILD_TYPE "Debug" )
add_executable(list ${PROJECT_SOURCE_DIR}/src/list.c)