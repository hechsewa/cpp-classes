//
// Created by hushmans on 03.05.17.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <iostream.h>
#include <string>
#include <stdexcept>
#include <memory>
#include <vector>
#include <regex>
#include <sstream>
using namespace std;

namespace moviesubs {
    class MovieSubtitles {
    public:
        MovieSubtitles()=default; //konstruktor
        void ShiftAllSubtitlesBy(int delay, int fps, std::istream *in, std::ostream *out);
        virtual void Delay(const char* in, const char* out, int delay, int fps);
    private:
    };

    /***********************/
    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        MicroDvdSubtitles()=default; //konstruktor
    private:

    };
}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
