//
// Created by hushmans on 27.03.17.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <algorithm>
#include <cstring>
#include <experimental/string_view>
#include <set>

using ::std::swap;

namespace pool {
    class TextPool {
    public:
        TextPool()= default; //domyslny konstruktor
        TextPool(const std::initializer_list<std::experimental::string_view> &in) : poolset_(in) {}

        TextPool(TextPool &&pool); //konstruktor przenoszący
        TextPool &operator=(TextPool &&pool); //operator przenoszący
        TextPool(const TextPool &pool) = delete; //konstruktor kopiujący
        TextPool &operator=(const TextPool &pool) = delete; //operator przypisania
        ~TextPool()=default; //destruktor

        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;
        std::set<std::experimental::string_view> poolset_;

    //private:

    };

}

#endif //JIMP_EXERCISES_TEXTPOOL_H
