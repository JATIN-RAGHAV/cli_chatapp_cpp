cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(SuperProject)

add_subdirectory(backend)
add_subdirectory(frontend)
add_subdirectory(common)
