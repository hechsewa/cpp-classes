//
// Created by hushmans on 03.05.17.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <string>
#include <iostream>
#include <stdexcept>
#include <memory>
#include <vector>
#include <regex>
#include <sstream>
using namespace std;

namespace moviesubs {
    class MovieSubtitles {
    public:
        virtual void ShiftAllSubtitlesBy(int delay, int fps, std::istream *in, std::ostream *out)=0;
    };

    /***************MicroDvDSubtitles******************/
    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        void ShiftAllSubtitlesBy(int delay, int fps, std::istream *in, std::ostream *out) override;

        MicroDvdSubtitles()=default;
    private:

    };
    /****************SubRipSubtitles*******************/
    class SubRipSubtitles : public MovieSubtitles {
    public:
        void ShiftAllSubtitlesBy(int delay, int fps, std::istream *in, std::ostream*out) override;

        SubRipSubtitles()=default;
    private:
        bool CompareTimes(const std::smatch &matches);
    };

    /**********************ErrorCases******************************/
    class MovieSubtitlesError : public std::runtime_error {
    public:
        MovieSubtitlesError(std::string str): std::runtime_error(str){};
    };


    class NegativeFrameAfterShift : public MovieSubtitlesError {
    public:
        NegativeFrameAfterShift(std::string str);
    };

    class SubtitleEndBeforeStart : public MovieSubtitlesError {
    public:
        SubtitleEndBeforeStart(int error_line, std::string line);
        int LineAt() const {return line_;}
    private:
        int line_;
    };

    class InvalidSubtitleLineFormat : public MovieSubtitlesError{
    public:
        InvalidSubtitleLineFormat();
    };

    class MissingTimeSpecification : public MovieSubtitlesError{
    public:
        MissingTimeSpecification();
    };

    class OutOfOrderFrames : public MovieSubtitlesError{
    public:
        OutOfOrderFrames();
    };

}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
