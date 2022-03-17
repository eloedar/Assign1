cmake_minimum_required(VERSION 3.21)
project(Assign1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Assign1
        assign1.c
        assign1.h
        assign1_mat.c
        assign1_mat.h)
