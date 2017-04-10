include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(TEST_LAB_NUMBER 7)

#######################################################################
##  TESTS
#######################################################################
add_gtest_with_memleak(array_fill libarrayfill)
add_gtest_with_memleak(comparable libcomparable)
add_gtest_with_memleak(iterable libiterable)


#######################################################################
##  ALL TESTS
#######################################################################
add_executable(lab7_all_tests ${SOURCE_FILES})

target_link_libraries(lab7_all_tests ${GTEST_LIBS})
target_link_libraries(lab7_all_tests libarrayfill)
target_link_libraries(lab7_all_tests libcomparable)
target_link_libraries(lab7_all_tests libiterable)
target_link_libraries(lab7_all_tests memleak)
target_link_libraries(lab7_all_tests stringutility)
