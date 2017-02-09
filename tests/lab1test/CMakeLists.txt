#message( STATUS "gtest_SOURCE_DIR: " ${gtest_SOURCE_DIR} )
#message( STATUS "gmock_SOURCE_DIR: " ${gmock_SOURCE_DIR} )

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

include_directories(../../lab1)

set(FACTORIAL_SRC FactorialTest.cpp)
set(REVERSE_STRING_SRC ReverseStringTest.cpp)
set(SOURCE_FILES ${FACTORIAL_SRC} ${REVERSE_STRING_SRC})

set(GTEST_LIBS gtest gtest_main gmock gmock_main)

add_executable(lab1_factorial_tests ${FACTORIAL_SRC})

target_link_libraries(lab1_factorial_tests ${GTEST_LIBS})
target_link_libraries(lab1_factorial_tests libfactorial)

add_executable(lab1_reverse_string_tests ${REVERSE_STRING_SRC})

target_link_libraries(lab1_reverse_string_tests ${GTEST_LIBS})
target_link_libraries(lab1_reverse_string_tests libreversestring)