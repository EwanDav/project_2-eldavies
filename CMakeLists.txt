cmake_minimum_required(VERSION 3.26)
project(song)

set(CMAKE_CXX_STANDARD 17)

add_executable(song main.cpp Song.h
        Queue.h
        Node.h
        Stack.h
)
