cmake_minimum_required(VERSION 3.28)

project(nuscenes-devkit-cpp)

add_subdirectory(extern/pybind11)
add_subdirectory(extern/nlohmann_json)
include_directories(include)
include_directories(extern/nlohmann_json/include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
add_library(nuscenes STATIC
                src/Nuscenes.cpp
                src/Attribute.cpp)
set_target_properties(nuscenes PROPERTIES POSITION_INDEPENDENT_CODE ON)

pybind11_add_module(_nuscenes src/main.cpp)
target_link_libraries(_nuscenes PRIVATE nuscenes)
target_compile_definitions(_nuscenes
                           PRIVATE VERSION_INFO=0.1.0)
