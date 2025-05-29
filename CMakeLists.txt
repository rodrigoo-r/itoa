include(FetchContent)

cmake_minimum_required(VERSION 3.30)
project(itoa C)

set(CMAKE_C_STANDARD 11)

add_library(itoa STATIC itoa.c
        itoa.h)


if(NOT FLUENT_LIBC_RELEASE) # Manually add libraries only if not in release mode
    FetchContent_Declare(
            std_bool
            GIT_REPOSITORY https://github.com/rodrigoo-r/std_bool
            GIT_TAG        master
    )

    FetchContent_Declare(
            types
            GIT_REPOSITORY https://github.com/rodrigoo-r/types
            GIT_TAG        master
    )

    FetchContent_MakeAvailable(std_bool)
    FetchContent_MakeAvailable(types)

    target_include_directories(itoa PRIVATE ${CMAKE_BINARY_DIR}/_deps/std_bool-src)
    target_link_libraries(itoa PRIVATE std_bool)
    target_include_directories(itoa PRIVATE ${CMAKE_BINARY_DIR}/_deps/types-src)
    target_link_libraries(itoa PRIVATE types)
endif ()