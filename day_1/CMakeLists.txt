# 声明一个 cmake 工程
project(Demo)
# 声明要求的 cmake 最低版本
cmake_minimum_required( VERSION 3.14 )
add_executable(list ${PROJECT_SOURCE_DIR}/src/list.c)