//
// Created by hushmans on 27.03.17.
//

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include "TextPool.h"

namespace pool {
    TextPool::TextPool(TextPool &&in){
        poolset_.clear();
        swap(poolset_, in.poolset_);
    }

    TextPool& TextPool::operator=(TextPool &&in) {
        if (this == &in) {
            return in;
        }
        else {
        poolset_.clear();
        swap(poolset_, in.poolset_);
        }
    }

    std::experimental::string_view TextPool::Intern(const std::string &str){
        for (auto com : poolset_){
            if(com.compare(str)==0){
                return com;
            }
        }
        std::experimental::string_view pool_sv {str};
        poolset_.insert(pool_sv);
        return pool_sv;
    }

    size_t TextPool::StoredStringCount() const {
        return poolset_.size();
    }
}