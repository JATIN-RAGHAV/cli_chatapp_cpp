cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(SuperProject)

list(APPEND CMAKE_PREFIX_PATH "$ENV{HOME}/.local")

add_subdirectory(backend)
add_subdirectory(frontend)
add_subdirectory(common)
