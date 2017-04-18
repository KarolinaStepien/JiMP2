
project(example)

set(HEDEAR_FILES Example.h)
set(SOURCE_FILES Example.cpp)

add_library(libexample STATIC ${SOURCE_FILES})
target_include_directories(libexample PUBLIC .)

add_executable(example ${SOURCE_FILES} main.cpp ../point3D/Point3D.cpp ../point3D/Point3D.h ../point3D/main.cpp ../shape/Shape.cpp ../shape/Shape.h ../shape/main.cpp)

target_link_libraries(example libexample)
