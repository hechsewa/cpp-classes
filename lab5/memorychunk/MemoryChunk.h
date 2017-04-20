//
// Created by Student on 30/03/17.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H

#include <cstdint>
#include <algorithm>

namespace memorychunk {

    class MemoryChunk {
    public:

        MemoryChunk();
        MemoryChunk(int param);
        MemoryChunk(const std::string name);
        MemoryChunk(const MemoryChunk &mc);
        MemoryChunk(MemoryChunk &&mc);

        MemoryChunk &operator=(const MemoryChunk &mc);
        MemoryChunk &operator=(MemoryChunk &&mc);
        ~MemoryChunk();
        MemoryChunk(size_t sz);
        int8_t *MemoryAt(size_t offset) const;
        size_t ChunkSize() const;
    };
}

#endif //JIMP_EXERCISES_MEMORYCHUNK_H
