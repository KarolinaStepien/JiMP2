cmake_minimum_required(VERSION 3.6)
project(jimp_exercises)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lab1)
add_subdirectory(tests)

include_directories(lab1/factorial)
