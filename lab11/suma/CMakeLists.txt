
project(suma)

set(HEDEAR_FILES Suma.h)
set(SOURCE_FILES Suma.cpp)

add_library(libsuma STATIC ${SOURCE_FILES})
target_include_directories(libsuma PUBLIC .)

add_executable(suma ${SOURCE_FILES} main.cpp)

target_link_libraries(suma libsuma)
