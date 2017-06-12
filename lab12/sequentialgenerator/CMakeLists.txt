project(sequentialgenerator)

set(HEDEAR_FILES SequentialGenerator.h)
set(SOURCE_FILES SequentialGenerator.cpp)

add_library(libsequentialgenerator STATIC ${SOURCE_FILES})
target_include_directories(libsequentialgenerator PUBLIC .)

add_executable(sequentialgenerator ${SOURCE_FILES} main.cpp)

target_link_libraries(sequentialgenerator libsequentialgenerator)