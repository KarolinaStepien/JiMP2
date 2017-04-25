include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(TEST_LAB_NUMBER 8)

#######################################################################
##  TESTS
#######################################################################
add_gtest_with_memleak(pesel libpesel)


#######################################################################
##  ALL TESTS
#######################################################################
add_executable(lab8_all_tests ${SOURCE_FILES})

target_link_libraries(lab8_all_tests ${GTEST_LIBS})
target_link_libraries(lab8_all_tests libpesel)
target_link_libraries(lab8_all_tests memleak)
target_link_libraries(lab8_all_tests stringutility)
