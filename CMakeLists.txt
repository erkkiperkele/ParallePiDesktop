cmake_minimum_required(VERSION 3.7)
project(ParallePiDesktop)

set(CMAKE_CXX_COMPILER=/usr/local/Cellar/gcc/6.2.0/bin/g++-6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")
set(SOURCE_FILES main.cpp ParallelCalculations.cpp ParallelCalculations.h)


add_executable(ParallePiDesktop ${SOURCE_FILES})