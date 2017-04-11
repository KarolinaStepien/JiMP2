
project(point3d)

set(HEDEAR_FILES Point3D.h)
set(SOURCE_FILES Point3D.cpp)

add_library(libpoint3d STATIC ${SOURCE_FILES})
target_include_directories(libpoint3d PUBLIC .)

add_executable(point3d ${SOURCE_FILES} main.cpp)

target_link_libraries(point3d libpoint3d)
