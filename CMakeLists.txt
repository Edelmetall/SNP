cmake_minimum_required(VERSION 3.21)
project(SNP C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_CXX_STANDARD 11)

set(PROJECT_HEADERS
        praktikum6/work/personen-verwaltung/src/list.h
        praktikum6/work/personen-verwaltung/src/person.h
        )
set(PROJECT_SOURCES
        praktikum6/work/personen-verwaltung/src/main.c
        praktikum6/work/personen-verwaltung/src/list.c
        praktikum6/work/personen-verwaltung/src/person.c
        )

add_executable(untitled1 praktikum6/work/personen-verwaltung/src/main.c)

