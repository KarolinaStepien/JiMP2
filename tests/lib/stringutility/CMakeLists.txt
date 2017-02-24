project(memleak)

set(STRING_UTILITY_HEDEAR_FILES StringUtility.h)
set(STRING_UTILITY_FILES StringUtility.cpp)

add_library(stringutitliy STATIC ${STRING_UTILITY_FILES})
target_include_directories(stringutitliy PUBLIC .)



