//
// Created by Student on 16/03/17.
//

#include <vector>
#include <sstream>
#include <regex>
#include <cmath>
#include "MinimalTimeDifference.h"

unsigned int minimaltimedifference::ToMinutes(std::string time_HH_MM) {
    unsigned int hour, min;
    std::string string_h, string_m;

    std::regex pattern {R"((\d{1,2})\:+(\d{1,2}))"};
    std::string line (time_HH_MM);
    std::smatch matches;
    if (regex_match(line, matches, pattern)) {
        string_h = matches[1];
        unsigned int h;
        std::istringstream iss(string_h);
        iss >> h;

        string_m = matches[2];
        unsigned int m;
        std::istringstream pss(string_m);
        pss >> m;

        hour=h*60;
        min=m;
    }
    return hour+min;
}

unsigned int minimaltimedifference::MinimalTimeDifference(std::vector<std::string> times) {
    unsigned int min=20000,min2=0;
    times.reserve(20000);

    for (unsigned int n = 0; n < times.size() - 1; n++) {
        for (unsigned int m = n+1; m < times.size(); m++) {
            if (abs(ToMinutes(times[n]) - ToMinutes(times[m])) > 720) {
                if (abs(ToMinutes(times[n]) - ToMinutes(times[m])) > min2) {
                    min2 = abs(ToMinutes(times[n]) - ToMinutes(times[m]));
                }
            }
            else {
                if (abs(ToMinutes(times[n]) - ToMinutes(times[m])) < min) {
                    min = abs(ToMinutes(times[n]) - ToMinutes(times[m]));
                }
            }
        }
    }
    min2=1440-min2;
    if(min<min2)
        return min;
    else
        return min2;
}