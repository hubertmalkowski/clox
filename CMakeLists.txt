cmake_minimum_required(VERSION 3.30)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled main.c
        chunk.c
        compiler.c
        debug.c
        memory.c
        scanner.c
        value.c
        vm.c
)
