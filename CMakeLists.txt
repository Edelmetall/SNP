cmake_minimum_required(VERSION 3.21)
project(SNP C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(prakikum2)

add_executable(aufgabe2 prakikum2/aufgabe2.c)
add_executable(aufgabe3 prakikum2/aufgabe3.c)

add_executable(aufgabe4 praktikum4/work/modularize/src/triangle.c)
