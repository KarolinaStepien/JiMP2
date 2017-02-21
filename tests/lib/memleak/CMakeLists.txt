project(memleak)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(MEM_LEAK_HEDEAR_FILES MemLeak.h)
set(MEM_LEAK_SOURCE_FILES MemLeak.cpp MemLeakTest.cpp)

add_library(memleak STATIC ${MEM_LEAK_SOURCE_FILES})
target_link_libraries(memleak ${GTEST_LIBS})
target_include_directories(memleak PUBLIC .)



