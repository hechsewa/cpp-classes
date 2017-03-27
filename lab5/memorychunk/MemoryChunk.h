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

        XXX();
        XXX(int param);
        XXX(const std::string name);
        XXX(const XXX &xxx);
        XXX(XXX &&xxx);

        XXX &operator=(const XXX &xxx);
        XXX &operator=(XXX &&xxx);
        ~XXX();
        MemoryChunk(size_t sz);
        int8_t *MemoryAt(size_t offset) const;
        size_t ChunkSize() const;
    };
}

#endif //JIMP_EXERCISES_MEMORYCHUNK_H
