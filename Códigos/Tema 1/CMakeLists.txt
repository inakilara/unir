cmake_minimum_required(VERSION 3.29)
project(Tema_1 C)

set(CMAKE_C_STANDARD 11)

add_executable(Tema_1
        hello_world.c)

TARGET_LINK_LIBRARIES(Tema_1 m)