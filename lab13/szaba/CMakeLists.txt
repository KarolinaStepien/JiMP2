
project(szaba)

set(HEDEAR_FILES Szaba.h SzabaTest.h)
set(SOURCE_FILES Szaba.cpp SzabaTest.cpp)

add_library(libszaba STATIC ${SOURCE_FILES})
target_include_directories(libszaba PUBLIC .)

add_executable(szaba ${SOURCE_FILES} main.cpp)

target_link_libraries(szaba libszaba)
