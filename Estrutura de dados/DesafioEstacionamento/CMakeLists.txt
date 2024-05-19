cmake_minimum_required(VERSION 3.27)
project(Supermercado C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Supermercado
        main.c
        estacionamento.c
        estacionamento.h)
