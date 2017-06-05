//
// Created by Student on 18/05/17.
//

#ifndef JIMP_EXERCISES_VALUE_H
#define JIMP_EXERCISES_VALUE_H

#include <vector>
#include <iostream>

using namespace std;

namespace maths {
    template<class T>
    auto Value(T in)->decltype(*in){
        return *in;
    }

    template<class U>
    U Mean(std::vector<U> vec){
        U sum=0;
        for (int i=0; i<vec.size(); i++){
            sum=sum+sum[i];
        }
        return sum/vec.size();
    }
}

#endif //JIMP_EXERCISES_VALUE_H
