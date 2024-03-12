cmake_minimum_required(VERSION 3.27)
project(maman14 C)

set(CMAKE_C_STANDARD 90)

add_executable(maman14 main.c preambley.c preambley.h table.c table.h constants.h test.c test.h)
