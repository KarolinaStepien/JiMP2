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

set(SOURCE_FILES ${ARRAY_2D_SRC})

#set(GTEST_LIBS gtest gtest_main gmock gmock_main)

add_executable(lab2_array_2d_step1_tests ${ARRAY_2D_STEP1_SRC})

target_link_libraries(lab2_array_2d_step1_tests ${GTEST_LIBS})
target_link_libraries(lab2_array_2d_step1_tests libmultidimarray)


add_executable(lab2_array_2d_step2_tests ${ARRAY_2D_STEP2_SRC})

target_link_libraries(lab2_array_2d_step2_tests ${GTEST_LIBS})
target_link_libraries(lab2_array_2d_step2_tests libmultidimarray)
target_link_libraries(lab2_array_2d_step2_tests memleak)

add_executable(lab2_array_2d_step3_tests ${ARRAY_2D_STEP3_SRC})

target_link_libraries(lab2_array_2d_step3_tests ${GTEST_LIBS})
target_link_libraries(lab2_array_2d_step3_tests libmultidimarray)
target_link_libraries(lab2_array_2d_step3_tests memleak)

add_executable(lab2_array_2d_step4_tests ${ARRAY_2D_STEP4_SRC})

target_link_libraries(lab2_array_2d_step4_tests ${GTEST_LIBS})
target_link_libraries(lab2_array_2d_step4_tests libmultidimarray)
target_link_libraries(lab2_array_2d_step4_tests memleak)

add_executable(lab2_array_2d_tests ${ARRAY_2D_SRC})

target_link_libraries(lab2_array_2d_tests ${GTEST_LIBS})
target_link_libraries(lab2_array_2d_tests libmultidimarray)
target_link_libraries(lab2_array_2d_tests memleak)


add_executable(lab2_all_tests ${SOURCE_FILES})

target_link_libraries(lab2_all_tests ${GTEST_LIBS})
target_link_libraries(lab2_all_tests libmultidimarray)
target_link_libraries(lab2_all_tests memleak)
