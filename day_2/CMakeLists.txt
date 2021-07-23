# 声明一个 cmake 工程
project(Demo)
# 声明要求的 cmake 最低版本
cmake_minimum_required( VERSION 3.14 )
include_directories(${PROJECT_SOURCE_DIR}/src/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/src UTHASH_TEST_SRC)
add_executable(uthash_test ${UTHASH_TEST_SRC})
