cmake_minimum_required(VERSION 3.6)
project(jimp_exercises)

set(CMAKE_CXX_STANDARD 14)

macro(add_subdirectory_if_exists DIR)
    #    message("add_subdirectory_if_exists")
    string(TOUPPER "${DIR}" DIR_UPPER)
    #    message("add_subdirectory_if_exists ${DIR_UPPER}")
    if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${DIR}/CMakeLists.txt")
        message("add_subdirectory_if_exists ${DIR_UPPER} EXISTS!")
        set("HAVE_DIR_${DIR_UPPER}" 1)
        add_subdirectory("${DIR}")
    endif ()
endmacro(add_subdirectory_if_exists)

add_subdirectory(lab1)
add_subdirectory(lab2)
add_subdirectory(lab3)
add_subdirectory(tests)

