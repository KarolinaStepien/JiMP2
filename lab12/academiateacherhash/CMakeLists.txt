project(teacherhash)

set(HEDEAR_FILES TeacherHash.h)
set(SOURCE_FILES TeacherHash.cpp)

add_library(libteacherhash STATIC ${SOURCE_FILES})
target_include_directories(libteacherhash PUBLIC .)

add_executable(teacherhash ${SOURCE_FILES} main.cpp)

target_link_libraries(teacherhash libteacherhash)