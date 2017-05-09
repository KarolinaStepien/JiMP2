project(moviesubs)

set(HEDEAR_FILES MovieSubtitles.h)
set(SOURCE_FILES MovieSubtitles.cpp)

add_library(libmoviesubtitles STATIC ${SOURCE_FILES} main.cpp)
target_include_directories(libmoviesubtitles PUBLIC .)

add_executable(moviesubtitles ${SOURCE_FILES} main.cpp)

target_link_libraries(moviesubtitles libmoviesubtitles)
