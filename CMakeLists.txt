cmake_minimum_required(VERSION 3.6)
project(jimp_exercises)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp tests/lab1/FactorialTest.cpp)

add_executable(jimp_exercises ${SOURCE_FILES})

include_directories(lab1/factorial)


add_subdirectory(lab1/factorial)
add_subdirectory(tests)

target_link_libraries(jimp_exercises lab1)