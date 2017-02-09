project(factorial)

set(HEDEAR_FILES Factorial.h)
set(SOURCE_FILES Factorial.cpp)

add_library(libfactorial STATIC ${SOURCE_FILES} ${HEDEAR_FILES})

add_executable(factorial ${SOURCE_FILES} ${HEADER_FILES} main.cpp)

target_link_libraries(factorial libfactorial)