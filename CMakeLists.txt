cmake_minimum_required(VERSION 3.28)

project(nuscenes-devkit-cpp)

add_subdirectory(extern/pybind11)
pybind11_add_module(_nuscenes src/main.cpp)
target_compile_definitions(_nuscenes
                           PRIVATE VERSION_INFO=0.1.0)
