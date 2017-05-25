include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(TEST_LAB_NUMBER 12)

#######################################################################
##  TESTS
#######################################################################
add_gtest_with_memleak(time_recorder libtimerecorder)
add_gtest_with_memleak(tree libtree)
add_gtest_with_memleak(student_hash libstudenthash)

#######################################################################
##  ALL TESTS
#######################################################################
add_executable(lab12_all_tests ${SOURCE_FILES})

target_link_libraries(lab12_all_tests ${GTEST_LIBS})
target_link_libraries(lab12_all_tests libtimerecorder)
target_link_libraries(lab12_all_tests libstudenthash)
target_link_libraries(lab12_all_tests libmemoryleak)
