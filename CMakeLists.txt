cmake_minimum_required(VERSION 3.13)
project(pimpl_sample)

set(CMAKE_CXX_STANDARD 11)

add_executable(pimpl_sample
        main.cpp
        hidden.impl.cpp
        )