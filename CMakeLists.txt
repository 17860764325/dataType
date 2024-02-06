cmake_minimum_required(VERSION 3.25)
project(untitled1)

set(CMAKE_CXX_STANDARD 17)
# 设置h头文件的路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/headSpace)

# 测试cMake的cpp文件路径
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/testCMake/*.cpp)

# dataType里面的cpp文件
file(GLOB SRC2 ${CMAKE_CURRENT_SOURCE_DIR}/dataType/1线性表/*.cpp)
file(GLOB SRC3 ${CMAKE_CURRENT_SOURCE_DIR}/dataType/2栈，队列，数组/*.cpp)
file(GLOB SRC4 ${CMAKE_CURRENT_SOURCE_DIR}/dataType/3串/*.cpp)
file(GLOB SRC5 ${CMAKE_CURRENT_SOURCE_DIR}/dataType/4树与二叉树/*.cpp)
#file(GLOB SRC6 ${CMAKE_CURRENT_SOURCE_DIR}/dataType/5图/*.cpp)
file(GLOB SRC8 ${CMAKE_CURRENT_SOURCE_DIR}/dataType/6查找/*.cpp)
file(GLOB SRC9 ${CMAKE_CURRENT_SOURCE_DIR}/dataType/7排序/*.cpp)
file(GLOB SRC7 ${CMAKE_CURRENT_SOURCE_DIR}/课后代码题目/图代码题/*.cpp)
file(GLOB SRC10 ${CMAKE_CURRENT_SOURCE_DIR}/课后代码题目/树形查找课后题/*.cpp)
file(GLOB SRC11 ${CMAKE_CURRENT_SOURCE_DIR}/课后代码题目/交换排序课后题/*.cpp)

# main.cpp的cpp文件路径
file(GLOB SRC1 ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

set(SRC ${SRC} ${SRC1} ${SRC2} ${SRC3} ${SRC4} ${SRC5} ${SRC6} ${SRC7} ${SRC8} ${SRC9} ${SRC10} ${SRC11})
#set(SRC ${SRC} ${SRC2})
#set(SRC ${SRC} ${SRC3})
#set(SRC ${SRC} ${SRC4})
#set(SRC ${SRC} ${SRC5})
message(${SRC})
add_executable(untitled1 ${SRC})
