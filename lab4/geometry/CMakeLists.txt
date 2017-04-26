project(geometry)

set(HEDEAR_FILES Square.h)
set(HEDEAR_FILES Point.h)

set(SOURCE_FILES Square.cpp)
set(SOURCE_FILES Point.cpp)

add_library(libsquare STATIC ${SOURCE_FILES})
add_library(libpoint STATIC ${SOURCE_FILES})

target_include_directories(libsquare PUBLIC .)
target_include_directories(libpoint PUBLIC .)

add_executable(square ${SOURCE_FILES} main.cpp)
add_executable(point ${SOURCE_FILES} main.cpp)

target_link_libraries(square libsquare)
target_link_libraries(point libpoint)
target_link_libraries(libsquare libpoint)