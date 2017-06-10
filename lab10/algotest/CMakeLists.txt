
project(algotest)

set(HEDEAR_FILES Algo.h)
set(SOURCE_FILES Algo.cpp)

add_library(libalgo STATIC ${SOURCE_FILES})
target_include_directories(libalgo PUBLIC .)

add_executable(algo ${SOURCE_FILES} main.cpp ../academiascheduler/AcademiaScheduler.cpp ../academiascheduler/AcademiaScheduler.h ../academiascheduler/main.cpp)

target_link_libraries(algo libalgo)
