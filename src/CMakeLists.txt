cmake_minimum_required(VERSION 3.4)
project(ProyectoMPointer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp MPointerGC/MPointerCG.cpp MPointerGC/MPointerCG.h MPointerGC MPointerGC/ListaMPointerGC.h MPointerGC/MPointerGC.cpp MPointerGC/MPointerGC.h MPointer/MPointer.h)
add_executable(ProyectoMPointer ${SOURCE_FILES} MPointerGC/ MPointerGC/ MPointerGC/ListaMPointerGC.h MPointerGC/MPointerGC.cpp MPointerGC/MPointerGC.h MPointer/MPointer.h)