project(jimp_excercises_tests)

add_subdirectory(lib/gtest-1.8.0)
set(GTEST_LIBS gtest gtest_main gmock gmock_main)

add_subdirectory(lib/stringutility)
add_subdirectory(lib/memleak)


macro(add_gtest TEST_NAME_TARGET SOLUTION_LIB_DEP)
    string(TOLOWER "${TEST_NAME_TARGET}" LOWER_TEST_NAME_TARGET)
    string(TOUPPER "${TEST_NAME_TARGET}" UPPER_TEST_NAME_TARGET)
    set(TEST_SOURCES_INTERNAL "${${UPPER_TEST_NAME_TARGET}_SRC}")
    set(TEST_TARGET_INTERNAL "lab${TEST_LAB_NUMBER}_${LOWER_TEST_NAME_TARGET}_tests")
    message("add_gtest_with_memleak target: ${TEST_TARGET_INTERNAL}")
    message("add_gtest_with_memleak src: ${TEST_SOURCES_INTERNAL}")
    message("add_gtest_with_memleak lib: ${SOLUTION_LIB_DEP}")
    add_executable("${TEST_TARGET_INTERNAL}" "${TEST_SOURCES_INTERNAL}")

    target_link_libraries("${TEST_TARGET_INTERNAL}" ${GTEST_LIBS})
    target_link_libraries("${TEST_TARGET_INTERNAL}" "${SOLUTION_LIB_DEP}")
    target_link_libraries("${TEST_TARGET_INTERNAL}" stringutility)
endmacro(add_gtest)

macro(add_gtest_with_memleak TEST_NAME_TARGET SOLUTION_LIB_DEP)
    add_gtest("${TEST_NAME_TARGET}" "${SOLUTION_LIB_DEP}")
    target_link_libraries("${TEST_TARGET_INTERNAL}" memleak)
endmacro(add_gtest_with_memleak)

macro(add_gtest_with_memleak_stepped TEST_NAME_TARGET)
    foreach (STEP ${ARGN})
        set(TEST_NAME_TARGET_STEPPED "${TEST_NAME_TARGET}_step${STEP}")
        string(REGEX REPLACE "_" "" SOLUTION_LIB_TO_REMOVE ${TEST_NAME_TARGET})
        set(SOLUTION_LIB_DEP "lib${SOLUTION_LIB_TO_REMOVE}")
        add_gtest_with_memleak("${TEST_NAME_TARGET_STEPPED}" "${SOLUTION_LIB_DEP}")
    endforeach ()
endmacro(add_gtest_with_memleak_stepped)

add_subdirectory(lab1test)
add_subdirectory(lab2test)
add_subdirectory(lab3test)




