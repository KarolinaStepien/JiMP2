#message( STATUS "gtest_SOURCE_DIR: " ${gtest_SOURCE_DIR} )
#message( STATUS "gmock_SOURCE_DIR: " ${gmock_SOURCE_DIR} )

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(SOURCE_FILES FactorialTest.cpp)

add_executable(jimp_exercises_lab1_tests ${SOURCE_FILES})


target_link_libraries(jimp_exercises_lab1_tests gtest gtest_main gmock gmock_main)
target_link_libraries(jimp_exercises_lab1_tests lab1)