cmake_minimum_required(VERSION 3.19)
project(cal_work_hours_cpp)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES
        main.cpp
        headers/common_headers.h
        headers/custom_func.h
        source/custom_func.cpp
#        test/test.cpp
)
include_directories(input/ output/)

add_executable(cal_work_hours_cpp ${SOURCE_FILES})