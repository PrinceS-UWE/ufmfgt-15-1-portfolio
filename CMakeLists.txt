cmake_minimum_required(VERSION 3.21)
project(MiniCourse C)

set(CMAKE_C_STANDARD 99)

add_executable(MiniCourse
        main.c
        IO.c
        IO.h
        waveform.h
        waveform.c
        )
target_link_libraries(MiniCourse m)
