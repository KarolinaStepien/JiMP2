project(timerecorder)

set(HEDEAR_FILES TimeRecorder.h)
set(SOURCE_FILES TimeRecorder.cpp)

add_library(libtimerecorder STATIC ${SOURCE_FILES})
target_include_directories(libtimerecorder PUBLIC .)

add_executable(timerecorder ${SOURCE_FILES} main.cpp)

target_link_libraries(timerecorder libtimerecorder)