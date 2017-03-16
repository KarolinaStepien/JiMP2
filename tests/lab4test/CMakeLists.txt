include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(TEST_LAB_NUMBER 4)

#######################################################################
##  TESTS
#######################################################################
#add_gtest_with_memleak_stepped(tiny_url 1 2)

add_gtest_with_memleak(url liburl)

#######################################################################
##  ALL TESTS
#######################################################################
add_executable(lab4_all_tests ${SOURCE_FILES})

target_link_libraries(lab4_all_tests ${GTEST_LIBS})
target_link_libraries(lab4_all_tests liburl)
target_link_libraries(lab4_all_tests memleak)
target_link_libraries(lab4_all_tests stringutility)
