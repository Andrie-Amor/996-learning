cmake_minimum_required(VERSION 3.27)
project(misc_scripts LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(copy_elison copy_elison.cpp)
add_executable(crtp crtp.cpp)
