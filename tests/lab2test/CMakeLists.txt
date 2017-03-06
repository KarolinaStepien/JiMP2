include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(TEST_LAB_NUMBER 2)


set(ARRAY_2D_STEP1_SRC Array2DStep1Test.cpp)
set(ARRAY_2D_STEP2_SRC Array2DStep2Test.cpp)
set(ARRAY_2D_STEP3_SRC Array2DStep3Test.cpp)
set(ARRAY_2D_STEP4_SRC Array2DStep4Test.cpp)
set(ARRAY_2D_SRC ${ARRAY_2D_STEP1_SRC} ${ARRAY_2D_STEP2_SRC} ${ARRAY_2D_STEP3_SRC} ${ARRAY_2D_STEP4_SRC})

set(POLYBIUS_STEP1_SRC PolybiusStep1Test.cpp)
set(POLYBIUS_STEP2_SRC PolybiusStep2Test.cpp)
set(POLYBIUS_SRC ${POLYBIUS_STEP1_SRC} ${POLYBIUS_STEP2_SRC})

set(GREATEST_PRODUCT_STEP1_SRC GreatestProductStep1Test.cpp)
set(GREATEST_PRODUCT_STEP2_SRC GreatestProductStep2Test.cpp)
set(GREATEST_PRODUCT_STEP3_SRC GreatestProductStep3Test.cpp)
set(GREATEST_PRODUCT_SRC ${GREATEST_PRODUCT_STEP1_SRC} ${GREATEST_PRODUCT_STEP2_SRC} ${GREATEST_PRODUCT_STEP3_SRC})

set(SIMPLE_FORWARD_LIST_STEP1_SRC SimpleForwardListStep1Test.cpp)
set(SIMPLE_FORWARD_LIST_STEP2_SRC SimpleForwardListStep2Test.cpp)
set(SIMPLE_FORWARD_LIST_STEP3_SRC SimpleForwardListStep3Test.cpp)
set(SIMPLE_FORWARD_LIST_SRC ${SIMPLE_FORWARD_LIST_STEP1_SRC} ${SIMPLE_FORWARD_LIST_STEP2_SRC} ${SIMPLE_FORWARD_LIST_STEP3_SRC})

set(XOR_CYPHER_BREAKER_SRC XorCypherBreakerTest.cpp)

set(SOURCE_FILES ${ARRAY_2D_SRC} ${POLYBIUS_SRC} ${GREATEST_PRODUCT_SRC} ${SIMPLE_FORWARD_LIST_SRC})

#set(GTEST_LIBS gtest gtest_main gmock gmock_main)

#######################################################################
##  ARRAY 2 D          STEP 1
#######################################################################
add_gtest(array_2d_step1 libarray2d)

#######################################################################
##  ARRAY 2 D          STEP 2 3 4
#######################################################################
add_gtest_with_memleak_stepped(array_2d 2 3 4)

#######################################################################
##  POLYBIUS          STEP 1 2
#######################################################################
add_gtest_with_memleak_stepped(polybius 1 2)

#######################################################################
##  GREATEST PRODUCT  STEP 1 2 3
#######################################################################
add_gtest_with_memleak_stepped(greatest_product 1 2 3)

#######################################################################
##  SIMPLE FORWARD LIST STEP 1 2 3
#######################################################################
add_gtest_with_memleak_stepped(simple_forward_list 1 2 3)

add_gtest_with_memleak(xor_cypher_breaker libxorcypherbreaker)

#######################################################################
##  ALL TESTS
#######################################################################
add_executable(lab2_all_tests ${SOURCE_FILES})

target_link_libraries(lab2_all_tests ${GTEST_LIBS})
target_link_libraries(lab2_all_tests libarray2d)
target_link_libraries(lab2_all_tests libpolybius)
target_link_libraries(lab2_all_tests libgreatestproduct)
target_link_libraries(lab2_all_tests libsimpleforwardlist)
target_link_libraries(lab2_all_tests memleak)
target_link_libraries(lab2_all_tests stringutility)
