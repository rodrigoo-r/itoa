cmake_minimum_required(VERSION 3.30)
project(itoa C)

set(CMAKE_C_STANDARD 11)

add_library(itoa STATIC include/fluent/itoa/itoa.c
        include/fluent/itoa/itoa.h)
