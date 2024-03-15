cmake_minimum_required(VERSION 3.27)
project(maman14 C)

set(CMAKE_C_STANDARD 90)

add_executable(maman14 main.c preambley.c preambley.h
        constants.h
        library.h
        states.c
        states.h
        table.c
        table.h
        tools.c
        tools.h
        typedefs.h
)
