project(memorychunk)

set(HEDEAR_FILES MemoryChunk.h)
set(SOURCE_FILES MemoryChunk.cpp)

add_library(libMemoryChunk STATIC ${SOURCE_FILES})
target_include_directories(libMemoryChunk PUBLIC .)

add_executable(MemoryChunk ${SOURCE_FILES} main.cpp)

target_link_libraries(MemoryChunk libxxx)