//
// Created by hushmans on 02.06.17.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <string>
#include <unordered_map>
#include <thread>
#include <chrono>

namespace profiling {

    template<typename T>
    auto TimeRecorder(T object){
        typedef std::chrono::high_resolution_clock hr_clock;
        static hr_clock::time_point begin = hr_clock::now();
        auto result = (object)();
        std::chrono::duration<double, std::milli> elapsed = hr_clock::now() - begin;
        return std::pair<decltype(result), double>(result, elapsed.count());
    };
}

#endif //JIMP_EXERCISES_TIMERECORDER_H
