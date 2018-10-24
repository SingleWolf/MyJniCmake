cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_VERBOSE_MAKEFILE on)

add_library(
        # 库名字
        jsoncpp
        # 库类型
        SHARED
        # 静态库将库类型由SHARED修改为STATIC
        #STATIC
        # 库包含的资源
        src/json_tool.h
        src/json_reader.cpp
        src/json_valueiterator.inl
        src/json_value.cpp
        src/json_writer.cpp
        src/version.h.in)

# 导出目录 此处的设置 导出主目录在 Project/export文件夹内。
set(export_dir ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../export)

set_target_properties(
        # 库名字
        jsoncpp
        # 设置输出.so动态库的路径
        PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${export_dir}/libsojsoncpp/lib/${ANDROID_ABI}"
        # 设置输出.a静态库的路径
        # 将 LIBRARY_OUTPUT_DIRECTORY 修改为 ARCHIVE_OUTPUT_DIRECTORY
        # 方便查看 生成的a文件目录修改一下 即 将 libsojsoncpp 修改为 libajsoncpp
        #PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${export_dir}/libajsoncpp/lib/${ANDROID_ABI}"
)

#add_custom_command(
#        # POST_BUILD 处 有三个值可选
#        # 分别是:
#        # PRE_BUILD：在 hello 运行其他规则前执行
#        # PRE_LINK：在编译源文件之后但在 链接其他二进制文件 或 运行静态库的库管理器 或 归档工具 之前执行
#        # POST_BUILD：最后执行
#        TARGET jsoncpp POST_BUILD
#
#        # 拷贝命令 将 ${CMAKE_CURRENT_SOURCE_DIR}/src/json/allocator.h 文件拷贝到 ${export_dir}/libsojsoncpp/include/json/ 文件夹内 且名字和之前的相同
#        COMMAND "${CMAKE_COMMAND}" -E copy "${CMAKE_CURRENT_SOURCE_DIR}/src/json/allocator.h" "${export_dir}/libsojsoncpp/include/json/allocator.h"
#
#        COMMAND "${CMAKE_COMMAND}" -E copy "${CMAKE_CURRENT_SOURCE_DIR}/src/json/config.h" "${export_dir}/libsojsoncpp/include/json/config.h"
#
#        COMMAND "${CMAKE_COMMAND}" -E copy "${CMAKE_CURRENT_SOURCE_DIR}/src/json/forwards.h" "${export_dir}/libsojsoncpp/include/json/forwards.h"
#
#        COMMAND "${CMAKE_COMMAND}" -E copy "${CMAKE_CURRENT_SOURCE_DIR}/src/json/features.h" "${export_dir}/libsojsoncpp/include/json/features.h"
#
#        COMMAND "${CMAKE_COMMAND}" -E copy "${CMAKE_CURRENT_SOURCE_DIR}/src/json/value.h" "${export_dir}/libsojsoncpp/include/json/value.h"
#
#        COMMAND "${CMAKE_COMMAND}" -E copy "${CMAKE_CURRENT_SOURCE_DIR}/src/json/reader.h" "${export_dir}/libsojsoncpp/include/json/reader.h"
#
#        COMMAND "${CMAKE_COMMAND}" -E copy "${CMAKE_CURRENT_SOURCE_DIR}/src/json/writer.h" "${export_dir}/libsojsoncpp/include/json/writer.h"
#
#        COMMAND "${CMAKE_COMMAND}" -E copy "${CMAKE_CURRENT_SOURCE_DIR}/src/json/assertions.h" "${export_dir}/libsojsoncpp/include/json/assertions.h"
#
#        COMMAND "${CMAKE_COMMAND}" -E copy "${CMAKE_CURRENT_SOURCE_DIR}/src/json/autolink.h"  "${export_dir}/libsojsoncpp/include/json/autolink.h"
#
#        COMMAND "${CMAKE_COMMAND}" -E copy "${CMAKE_CURRENT_SOURCE_DIR}/src/json/json.h"  "${export_dir}/libsojsoncpp/include/json/json.h"
#
#        COMMAND "${CMAKE_COMMAND}" -E copy "${CMAKE_CURRENT_SOURCE_DIR}/src/json/version.h"  "${export_dir}/libsojsoncpp/include/json/version.h"
#)

#优化复制文件后的配置
add_custom_command(
        TARGET jsoncpp POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/src/json" "${export_dir}/libsojsoncpp/include/json/"
        # 生成的a文件目录修改一 将${CMAKE_CURRENT_SOURCE_DIR}/src/json 文件夹下的文件 导出到 ${export_dir}/libajsoncpp/include/json/ 文件夹内
        #COMMAND "${CMAKE_COMMAND}" -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/src/json" "${export_dir}/libajsoncpp/include/json/"
)
