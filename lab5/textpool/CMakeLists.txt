project(textpool)

set(HEDEAR_FILES TextPool.h)
set(SOURCE_FILES TextPool.cpp)

add_library(libtextpool STATIC ${SOURCE_FILES})
target_include_directories(libtextpool PUBLIC .)

add_executable(textpool ${SOURCE_FILES} main.cpp)

target_link_libraries(textpool libtextpool)