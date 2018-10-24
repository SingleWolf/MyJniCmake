# CMake最低版本
cmake_minimum_required(VERSION 3.4.1)

#编译so/a文件
set(CMAKE_VERBOSE_MAKEFILE on)

# 设置资源主目录 CMAKE_CURRENT_SOURCE_DIR 代表当前CMakeLists.txt 所在的目录
set(lib_src_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# 设置CMake编译后文件的存放的临时目录
set(lib_build_DIR $ENV{HOME}/tmp)

# 将生成的临时文件放在 lib_build_DIR 中
file(MAKE_DIRECTORY ${lib_build_DIR})

# 添加子项目
add_subdirectory(${lib_src_DIR}/jsoncpp ${lib_build_DIR}/jsoncpp)