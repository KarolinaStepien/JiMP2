include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(TEST_LAB_NUMBER 3)


set(SMART_TREE_SRC SmartTreeTest.cpp)

set(SOURCE_FILES ${SMART_TREE_SRC})


#######################################################################
##  TESTS
#######################################################################
add_gtest_with_memleak(smart_tree libsmarttree)


#######################################################################
##  ALL TESTS
#######################################################################
add_executable(lab3_all_tests ${SOURCE_FILES})

target_link_libraries(lab3_all_tests ${GTEST_LIBS})
target_link_libraries(lab3_all_tests libsmarttree)
target_link_libraries(lab3_all_tests memleak)
target_link_libraries(lab3_all_tests stringutility)
