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

        //rule of 5
        MemoryChunk(const MemoryChunk &mch);
        MemoryChunk(MemoryChunk &&mch);
        MemoryChunk &operator=(const MemoryChunk &mch);
        MemoryChunk &operator=(MemoryChunk &&mch);
        ~MemoryChunk();
        //end rule of 5

        MemoryChunk(size_t sz);
        int8_t *MemoryAt(size_t offset) const;
        size_t ChunkSize() const;

    private:
        int8_t *memory_;
        size_t howbig_;
    };
}

#endif //JIMP_EXERCISES_MEMORYCHUNK_H
