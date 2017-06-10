
project(juwejuwe)

set(HEDEAR_FILES JuweJuwe.h)
set(SOURCE_FILES JuweJuwe.cpp)

add_library(libjuwejuwe STATIC ${SOURCE_FILES} main.cpp)
target_include_directories(libjuwejuwe PUBLIC .)

add_executable(juwejuwe ${SOURCE_FILES} main.cpp)

target_link_libraries(juwejuwe libjuwejuwe)

