cmake_minimum_required(VERSION 3.29)
project(Tema_4 C)

set(CMAKE_C_STANDARD 11)

add_executable(Tema_4
    Calculadora.c)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    add_executable(debug_target Calculadora.c)
endif()

