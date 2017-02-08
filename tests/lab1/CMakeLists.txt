#message( STATUS "gtest_SOURCE_DIR: " ${gtest_SOURCE_DIR} )
#message( STATUS "gmock_SOURCE_DIR: " ${gmock_SOURCE_DIR} )

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(SOURCE_FILES FactorialTest.cpp)
set(GTEST_LIBS gtest gtest_main gmock gmock_main)

add_executable(lab1_factorial_tests ${SOURCE_FILES})


target_link_libraries(lab1_factorial_tests ${GTEST_LIBS})
target_link_libraries(lab1_factorial_tests lab1)