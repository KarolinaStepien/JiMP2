include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(TEST_LAB_NUMBER 3)


set(SMART_TREE_STEP1_SRC SmartTreeStep1Test.cpp)
set(SMART_TREE_STEP2_SRC SmartTreeStep2Test.cpp)
set(SMART_TREE_STEP3_SRC SmartTreeStep3Test.cpp)
set(SMART_TREE_STEP4_SRC SmartTreeStep4Test.cpp)
set(SMART_TREE_STEP5_SRC SmartTreeStep5Test.cpp)

set(TINY_URL_STEP1_SRC TinyUrlStep1Test.cpp)
set(TINY_URL_STEP2_SRC TinyUrlStep2Test.cpp)

set(C_COUNTER_SRC CCounterTest.cpp)

set(MINIMAL_TIME_DIFFERENCE_SRC MinimalTimeDifferenceTest.cpp)

set(SOURCE_FILES ${SMART_TREE_STEP1_SRC} ${SMART_TREE_STEP2_SRC} ${SMART_TREE_STEP3_SRC} ${SMART_TREE_STEP4_SRC} ${SMART_TREE_STEP5_SRC})


#######################################################################
##  TESTS
#######################################################################
add_gtest_with_memleak_stepped(smart_tree 1 2 3 4 5)

add_gtest_with_memleak_stepped(tiny_url 1 2)

add_gtest_with_memleak(c_counter libccounter)

add_gtest_with_memleak(minimal_time_difference libminimaltimedifference)

#######################################################################
##  ALL TESTS
#######################################################################
add_executable(lab3_all_tests ${SOURCE_FILES})

target_link_libraries(lab3_all_tests ${GTEST_LIBS})
target_link_libraries(lab3_all_tests libsmarttree)
target_link_libraries(lab3_all_tests memleak)
target_link_libraries(lab3_all_tests stringutility)
