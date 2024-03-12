cmake_minimum_required(VERSION 3.27)
project(maman14 C)

set(CMAKE_C_STANDARD 90)

add_executable(maman14 main.c preambley.c preambley.h constants.h library.h states.h states.c table.h table.c test.h tools.h tools.c typedefs.h)
