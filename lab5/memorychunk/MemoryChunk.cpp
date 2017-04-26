//
// Created by Student on 30/03/17.
//

#include <cstdint>
#include <algorithm>
#include "MemoryChunk.h"

using namespace std;

namespace memorychunk {
    MemoryChunk::~MemoryChunk(){
        delete memory_;
    }

    MemoryChunk::MemoryChunk(size_t sz){
        
    }
}



