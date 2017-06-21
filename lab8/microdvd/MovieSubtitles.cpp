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

    /*****************MicroDvd*********************/

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

    /*****************SubRip********************/

    void SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::istream *in, std::ostream *out){
        if (fps<=0)
            throw std::invalid_argument("Invalid fps");

        std::string str;
        std::regex pattern {R"((\d{2}):(\d{2}):(\d{2}),(\d{3}) --> (\d{2}):(\d{2}):(\d{2}),(\d{3})"};
        //00:20:41,150 --> 00:20:45,109
        //hour:min:sec,milisec --> hour:min:sec,milisec
        //matches[1]:matches[2]:matches[3],matches[4] --> matches[5]:matches[6]:matches[7], matches[8]
        int counter=0;
        std::smatch matches;

        while(getline(*in,str,'\n')){
            ++counter;
            if(counter!=std::stoi(str)){
                throw OutOfOrderFrames(); }

            (*out) << str << '\n';
            getline(*in, str, '\n');

            if(std::regex_search(str, matches, pattern)){
                CompareTimes(matches, str, counter, delay);
                (*out) << matches[1] << ":" << matches[2] << ":";
                int milisec=std::stoi(matches[4])+delay;
                if(milisec<0) {
                    throw NegativeFrameAfterShift(str); }
                /******start subtitles time******/
                if(milisec<1000){
                    std::string tmp_ms = std::to_string(milisec);
                    while(tmp_ms.size()<3){
                        tmp_ms='0'+tmp_ms;
                    }
                    (*out) << matches[3] << "," << tmp_ms <<" --> ";
                }
                else {
                    int sec = std::stoi(matches[3])+milisec/1000;
                    milisec%=1000;
                    std::string tmp_ms = std::to_string(milisec);
                    while(tmp_ms.size()<3){
                        tmp_ms='0'+tmp_ms;
                    }
                    std::string tmp_sec = std::to_string(sec);
                    while(tmp_sec.size()<2) {
                        tmp_sec = '0' + tmp_sec;
                    }
                    (*out) << tmp_sec << "," << tmp_ms << " --> ";
                }
                /*****end subtitles time*****/
                (*out)<<matches[5]<<":"<<matches[6]<<":";
                milisec = std::stoi(matches[8])+delay;
                if(milisec<1000){
                    std::string tmp_ms=std::to_string(milisec);
                    while(tmp_ms.size()<3){
                        tmp_ms='0'+tmp_ms;
                    }
                    (*out) << matches[7] << "," << tmp_ms <<" --> ";
                }
                else{
                    int sec = std::stoi(matches[7])+milisec/1000;
                    milisec%=1000;
                    std::string tmp_ms = std::to_string(milisec);
                    while(tmp_ms.size()<3){
                        tmp_ms='0'+tmp_ms;
                    }
                    std::string tmp_sec = std::to_string(sec);
                    while(tmp_sec.size()<2){
                        tmp_sec = '0'+tmp_sec;
                    }
                    (*out)<<tmp_sec<<","<<tmp_ms<<'\n';
                }
            }
            /**********letters or invalid numbers in subrip format**********/
            else {
                std::regex letters {R"([a-zA-Z]+)"};
                std::smatch letters_matches;
                if(std::regex_search(str,letters_matches,letters)){
                    throw MissingTimeSpecification();}
                else {
                    throw InvalidSubtitleLineFormat(); }
            }

            while(str!=""){
                getline(*in,str,'\n');
                (*out)<<str;
                if(!in->eof()){
                    (*out)<<'\n';
                }
            }
        }
    }

    void SubRipSubtitles::CompareTimes(std::smatch matches, std::string str, int counter, int delay){
        int min=60*60*1000;
        int sec=60*1000;
        int ms=1000;
        long start_time = std::stoi(matches[1])*min + std::stoi(matches[2])*sec + std::stoi(matches[3])*ms + std::stoi(matches[4]);
        long end_time = std::stoi(matches[5])*min + std::stoi(matches[6])*sec + std::stoi(matches[7])*ms + std::stoi(matches[8]);
        if (end_time<start_time)
            throw SubtitleEndBeforeStart(counter, str);
        if (start_time+delay<0 or end_time+delay<0)
            throw NegativeFrameAfterShift(str);
    }

    /**************Error Cases *************/

    NegativeFrameAfterShift::NegativeFrameAfterShift(std::string str):MovieSubtitlesError("NegativeFrameAfterShift"){}

    MissingTimeSpecification::MissingTimeSpecification():MovieSubtitlesError("MissingTimeSpecification"){}

    OutOfOrderFrames::OutOfOrderFrames():MovieSubtitlesError("OutOfOrderFrames"){}

    InvalidSubtitleLineFormat::InvalidSubtitleLineFormat():MovieSubtitlesError("InvalidSubtitleLineFormat"){}

    SubtitleEndBeforeStart::SubtitleEndBeforeStart(int error_line, std::string line) : MovieSubtitlesError(
            "At line " + std::to_string(error_line) + ": " + line), line_(error_line) {}

}
