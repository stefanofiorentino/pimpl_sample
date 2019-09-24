cmake_minimum_required(VERSION 3.13)
project(pimpl_sample)

set(CMAKE_CXX_STANDARD 14)

add_executable(pimpl_sample
        main.cpp
        )

add_library(pimpl_sample_lib SHARED
        widget.impl.cpp
        )

target_link_libraries(pimpl_sample
        pimpl_sample_lib
        )