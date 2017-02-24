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

set(GREATEST_PRODUCT_STEP1_SRC GreatestProduct.cpp)

set(SOURCE_FILES ${ARRAY_2D_SRC} ${POLYBIUS_SRC})

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

add_gtest_with_memleak_stepped(greatest_product 1)

#######################################################################
##  ALL TESTS
#######################################################################
add_executable(lab2_all_tests ${SOURCE_FILES})

target_link_libraries(lab2_all_tests ${GTEST_LIBS})
target_link_libraries(lab2_all_tests libarray2d)
target_link_libraries(lab2_all_tests libpolybius)
target_link_libraries(lab2_all_tests memleak)
