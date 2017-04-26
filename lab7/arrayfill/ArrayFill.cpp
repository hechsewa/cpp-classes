//
// Created by Student on 20/04/17.
//

#include <random>
#include <vector>
#include <memory>
#include "ArrayFill.h"

using namespace arrays;

int arrays::UniformFill::Value(int index) const {
    return value_;
}

int arrays::IncrementalFill::Value(int index) const {
    return b_ + a_ * index;
}

int arrays::SquaredFill::Value(int index) const {
    return b_ + a_ * index * index;
}

int arrays::RandomFill::Value(int index) const {
    return (*distribution_) (*generator_);
}

void arrays::FillArray(std::size_t size, const ArrayFill &filler, std::vector<int> *v) {
    v->clear();
    v->reserve(size);
    for (std::size_t i = 0; i < size; i++) {
        v->emplace_back(filler.Value(i));
    }
}
