
project(addition)

set(HEDEAR_FILES Addition.h)
set(SOURCE_FILES Addition.cpp)

add_library(libaddition STATIC ${SOURCE_FILES})
target_include_directories(libaddition PUBLIC .)

add_executable(addition ${SOURCE_FILES} main.cpp)

target_link_libraries(addition libaddition)

