#cmake file for cmaketest

set (MY_PROJECT_NAME cmaketest) 

#定义工程说明
project(${MY_PROJECT_NAME})
cmake_minimum_required(VERSION 2.6.0)

#定义solution dir
set(SOLUTION_DIR ../../)
#定义头文件位置
include_directories(../include)
#设置源文件位置
set(SRC_DIR ../src/)
#设置库文件目录
link_directories(${PROJECT_BINARY_DIR}/../lib)

#设置编译选项
#SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -std=c++0x")
SET(CMAKE_CXX_FLAGS_DEBUG "ENV{CXX_FLAGS} -g3 -O0 -std=c++0x -Wall -Wno-unused-variable")
SET(CMAKE_BUILD_TYPE Debug)

#Release时开启此项
SET(CMAKE_CXX_FLAGS_RELEASE "ENV{CXX_FLAGS} -O3 -Wall")

#add_definitions(-D_DEBUG_H)
#add_definitions(-D_DEBUG_Y)
#add_definitions(-D_DEBUG_Y_DB)
#add_definitions(-D_DEBUG_Z)

#内存数据库头文件
#if(UNIX AND CMAKE_SIZEOF_VOID_P EQUAL 4)
# include_directories(../include/linux/32bit)
# include_directories(${SOLUTION_DIR}p_include/extremedb/extremedb32/incldue)
# message(STATUS "32 BIT linux platform")
#else if(UNIX AND CMAKE_SIZEOF_VOID_P EQUAL 8)
# include_directories(../include/linux/64bit)
# include_directories(${SOLUTION_DIR}p_include/extremedb/extremedb64/incldue)
# message(STATUS "64 BIT linux platform")
#elseif(WIN32)
# message(STATUS "32 BIT WINDOWA platform")
#endif(UNIX AND CMAKE_SIZEOF_VOID_P EQUAL 4)

include_directories(${SOLUTION_DIR}./src)
#include_directories(${SOLUTION_DIR}./src/core)
#include_directories(${SOLUTION_DIR}./src/adapter)
#include_directories(${SOLUTION_DIR}./include)

#设置源文件位置
set(SRC_DIR ../src/)
##
set(SRC_LIST
${SRC_DIR}helloworld.c
#${SRC_DIR}./core/span_algorithm.cpp
#${SRC_DIR}./adapter/price_model/span_algorithm.cpp
)

#编译可执行文件
add_executable(${MY_PROJECT_NAME} ${SRC_LIST})
#输出位置
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin)

#设置库文件
#target_link_libraries(${MY_PROJECT_NAME} pthread dl libociei.so)
#add_custom_command(TARGET ${MY_PROJECT_NAME} POST_BUILD_COMMAND cp ${EXECUTABLE_OUTPUT_PATH}/${MY_PROJECT_NAME} ${SOLUTION_DIR}/submit/bin/)



