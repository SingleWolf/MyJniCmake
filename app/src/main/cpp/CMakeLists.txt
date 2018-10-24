# CMake最低版本
cmake_minimum_required(VERSION 3.4.1)
# 将需要打包的资源添加进来
add_library(
        # 库名字
        native_hello
        # 库类型
        SHARED
        # 包含的cpp
        native_hello.cpp
)

#链接so/a库文件
# 设置变量 找到存放资源的目录，".."代表上一级目录
set(export_dir ${CMAKE_SOURCE_DIR}/../../../../export)

# 添加.so动态库(jsoncpp)
add_library(lib_so_jsoncpp SHARED IMPORTED)
# 添加.a静态库(jsoncpp)
#add_library(lib_a_jsoncpp STATIC IMPORTED)

# 链接(jsoncpp.so)
set_target_properties(
        # 库名字
        lib_so_jsoncpp
        # 库所在的目录
        PROPERTIES IMPORTED_LOCATION ${export_dir}/libsojsoncpp/lib/${ANDROID_ABI}/libjsoncpp.so)
# 链接(jsoncpp.a)
#set_target_properties(
#        lib_a_jsoncpp
#        PROPERTIES IMPORTED_LOCATION ${export_dir}/libajsoncpp/lib/${ANDROID_ABI}/libjsoncpp.a)

# 链接头文件(jsoncpp.so)
target_include_directories(
        native_hello
        PRIVATE
        # native_hello 需要的头文件
        ${export_dir}/libsojsoncpp/include
)
# 链接头文件(jsoncpp.a)
#target_include_directories(
#        native_hello
#        PRIVATE
#        # native_hello 需要的头文件
#        ${export_dir}/libajsoncpp/include
#)

# 链接项目中
target_link_libraries(
        native_hello
        android
        log
        # 链接 jsoncpp.so
        lib_so_jsoncpp
        # 链接 jsoncpp.a
#        lib_a_jsoncpp
)
