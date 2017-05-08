//
// Created by hushmans on 03.05.17.
//
#include <string>
#include <stdexcept>
#include <memory>
#include <vector>
#include <regex>
#include "MovieSubtitles.h"

using namespace std;

namespace moviesubs{

    /**********MicroDvdSubtitles********/

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::istream *in, std::ostream *out){
        if (fps<=0)
            throw std::invalid_argument("Invalid fps");
        std::string str;
        int counter=0;
        int added_zero = (delay*fps)/1000;
        std::regex results {R"(\{(\d+)\}\{(\d+)\}(.*))"};
        std::smatch matches;

        while(getline(*in,str,'\n')){
            ++counter;
            if(std::regex_search(str, matches, results)) {
                int start = std::stoi(matches[1]) + added_zero;
                int end = std::stoi(matches[2]) + added_zero;
                if (end < start) {
                    throw SubtitleEndBeforeStart(counter, str); }
                if (start < 0)
                    throw NegativeFrameAfterShift(str);
                (*out) << "{" << start << "}";
                (*out) << "{" << end << "}";
                (*out) << matches[3] << "\n";
            } else
                throw InvalidSubtitleLineFormat();
            }
        }



    //bool SubRipSubtitles::CompareTimes();

    /**************Error Cases *************/

    NegativeFrameAfterShift::NegativeFrameAfterShift(std::string str):MovieSubtitlesError("NegativeFrameAfterShift"){}

    MissingTimeSpecification::MissingTimeSpecification():MovieSubtitlesError("MissingTimeSpecification"){}

    OutOfOrderFrames::OutOfOrderFrames():MovieSubtitlesError("OutOfOrderFrames"){}

    InvalidSubtitleLineFormat::InvalidSubtitleLineFormat():MovieSubtitlesError("InvalidSubtitleLineFormat"){}

    SubtitleEndBeforeStart::SubtitleEndBeforeStart(int error_line, std::string line) : MovieSubtitlesError(
            "At line " + std::to_string(error_line) + ": " + line), line_(error_line) {}

}
