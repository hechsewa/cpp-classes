//
// Created by Student on 20/04/17.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H
#include <random>
#include <vector>
#include <memory>

using std::default_random_engine;
using std::uniform_int_distribution;
using std::unique_ptr;

namespace arrays {
    class ArrayFill {
    public:
        virtual int Value(int index) const =0;
    };

    class UniformFill : public ArrayFill {
    public:
        UniformFill(int value = 0) : value_{value} {}

        int Value(int index) const override;

    private:
        int value_;
    };

    class IncrementalFill : public ArrayFill {
    public:
        IncrementalFill(int b = 0, int a = 1) : b_{b}, a_{a} {}

        int Value(int index) const override;

    private:
        int b_, a_;
    };

    class SquaredFill : public ArrayFill {
    public:
        SquaredFill(int a = 1, int b = 0) : a_{a}, b_{b} {}

        int Value(int index) const override;

    private:
        int a_, b_;
    };

    class RandomFill : public ArrayFill {
    public:
        RandomFill(unique_ptr<default_random_engine> generate, unique_ptr<uniform_int_distribution<int>> distribute): generator_(move(generate)), distribution_(move(distribute)) {}

        virtual int Value(int index) const override;

    private:
        unique_ptr<default_random_engine> generator_;
        unique_ptr<uniform_int_distribution<int>> distribution_;
    };


    void FillArray(std::size_t size, const ArrayFill &filler, std::vector<int> *v);
}


#endif //JIMP_EXERCISES_ARRAYFILL_H
