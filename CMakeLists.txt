cmake_minimum_required(VERSION 3.30)
project(clox C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

add_executable(clox main.c
        chunk.c
        compiler.c
        debug.c
        memory.c
        scanner.c
        value.c
        object.c
        vm.c
        table.c
)
