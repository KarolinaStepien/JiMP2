project(jimp_excercises_tests)

add_subdirectory(lib/gtest-1.8.0)

set(GTEST_LIBS gtest gtest_main gmock gmock_main)

add_subdirectory(lib/memleak)
add_subdirectory(lab1test)
add_subdirectory(lab2test)


