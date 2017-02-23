include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(TEST_LAB lab2)

#set(MEM_LEAK_SRC ../lib/memleak/MemLeak.cpp)
#set(MEM_LEAK_SRC ${MEM_LEAK_SOURCE_FILES})


set(ARRAY_2D_STEP1_SRC Array2DStep1Test.cpp)
set(ARRAY_2D_STEP2_SRC Array2DStep2Test.cpp)
set(ARRAY_2D_STEP3_SRC Array2DStep3Test.cpp)
set(ARRAY_2D_STEP4_SRC Array2DStep4Test.cpp)
set(ARRAY_2D_SRC ${ARRAY_2D_STEP1_SRC} ${ARRAY_2D_STEP2_SRC} ${ARRAY_2D_STEP3_SRC} ${ARRAY_2D_STEP4_SRC})

set(POLYBIUS_STEP1_SRC PolybiusStep1Test.cpp)
set(POLYBIUS_STEP2_SRC PolybiusStep2Test.cpp)

set(SOURCE_FILES ${ARRAY_2D_SRC})

#set(GTEST_LIBS gtest gtest_main gmock gmock_main)

#######################################################################
##  ARRAY 2 D          STEP 1
#######################################################################
add_executable(lab2_array_2d_step1_tests ${ARRAY_2D_STEP1_SRC})

target_link_libraries(lab2_array_2d_step1_tests ${GTEST_LIBS})
target_link_libraries(lab2_array_2d_step1_tests libarray2d)

#######################################################################
##  ARRAY 2 D          STEP 2
#######################################################################
add_executable(lab2_array_2d_step2_tests ${ARRAY_2D_STEP2_SRC})

target_link_libraries(lab2_array_2d_step2_tests ${GTEST_LIBS})
target_link_libraries(lab2_array_2d_step2_tests libarray2d)
target_link_libraries(lab2_array_2d_step2_tests memleak)

#######################################################################
##  ARRAY 2 D          STEP 3
#######################################################################
add_executable(lab2_array_2d_step3_tests ${ARRAY_2D_STEP3_SRC})

target_link_libraries(lab2_array_2d_step3_tests ${GTEST_LIBS})
target_link_libraries(lab2_array_2d_step3_tests libarray2d)
target_link_libraries(lab2_array_2d_step3_tests memleak)

#######################################################################
##  ARRAY 2 D          STEP 4
#######################################################################
add_executable(lab2_array_2d_step4_tests ${ARRAY_2D_STEP4_SRC})

target_link_libraries(lab2_array_2d_step4_tests ${GTEST_LIBS})
target_link_libraries(lab2_array_2d_step4_tests libarray2d)
target_link_libraries(lab2_array_2d_step4_tests memleak)

#######################################################################
##  ARRAY 2 D          ALL
#######################################################################
add_executable(lab2_array_2d_tests ${ARRAY_2D_SRC})

target_link_libraries(lab2_array_2d_tests ${GTEST_LIBS})
target_link_libraries(lab2_array_2d_tests libarray2d)
target_link_libraries(lab2_array_2d_tests memleak)

#######################################################################
##  POLYBIUS           STEP 1
#######################################################################
add_executable(lab2_polybius_step1_tests ${POLYBIUS_STEP1_SRC})

target_link_libraries(lab2_polybius_step1_tests ${GTEST_LIBS})
target_link_libraries(lab2_polybius_step1_tests libpolybius)
target_link_libraries(lab2_polybius_step1_tests memleak)

#######################################################################
##  POLYBIUS           STEP 1
#######################################################################
add_executable(lab2_polybius_step2_tests ${POLYBIUS_STEP2_SRC})

target_link_libraries(lab2_polybius_step2_tests ${GTEST_LIBS})
target_link_libraries(lab2_polybius_step2_tests libpolybius)
target_link_libraries(lab2_polybius_step2_tests memleak)

#######################################################################
##  ALL TESTS
#######################################################################
add_executable(lab2_all_tests ${SOURCE_FILES})

target_link_libraries(lab2_all_tests ${GTEST_LIBS})
target_link_libraries(lab2_all_tests libarray2d)
target_link_libraries(lab2_all_tests memleak)
