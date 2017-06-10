
project(romantoarabic)

set(HEDEAR_FILES RomanToArabic.h RomanToArabicTest.h)
set(SOURCE_FILES RomanToArabic.cpp RomanToArabicTest.cpp)

add_library(libromantoarabic STATIC ${SOURCE_FILES})
target_include_directories(libromantoarabic PUBLIC .)

add_executable(romantoarabic ${SOURCE_FILES} main.cpp)

target_link_libraries(romantoarabic libromantoarabic)
