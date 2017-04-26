project(point_op)

set(HEDEAR_FILES Point.h)
set(SOURCE_FILES Point.cpp)

add_library(libpoint_op STATIC ${SOURCE_FILES})
target_include_directories(libpoint_op PUBLIC .)

add_executable(point_op ${SOURCE_FILES} main.cpp)

target_link_libraries(point_op libpoint_op)