project(lab1)

set(HEDEAR_FILES Factorial.h)
set(SOURCE_FILES Factorial.cpp)

add_library(lab1 STATIC ${SOURCE_FILES} ${HEADER_FILES})