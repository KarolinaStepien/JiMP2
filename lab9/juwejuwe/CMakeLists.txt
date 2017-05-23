
project(juwe)

set(HEDEAR_FILES Juwe.h)
set(SOURCE_FILES Juwe.cpp)

add_library(libjuwe STATIC ${SOURCE_FILES} main.cpp)
target_include_directories(libjuwe PUBLIC .)

add_executable(juwe ${SOURCE_FILES} main.cpp)

target_link_libraries(juwe libjuwe)

