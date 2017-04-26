//
// Created by Student on 16/03/17.
//

#include <vector>
#include <sstream>
#include <regex>
#include <cmath>
#include "MinimalTimeDifference.h"

void minimaltimedifference::FromString(std::string string_m, unsigned int m) {
    std::istringstream iss(string_m);
    iss >> m;
}

unsigned int minimaltimedifference::ToMinutes(std::string time_HH_MM) {
    unsigned int min_count, min;

    std::regex pattern {R"((\d{1,2})\:+(\d{1,2}))"};
    std::string line (time_HH_MM);
    std::smatch matches;
    std::string hour_str;
    std::string minutes_str;
    if (regex_match(line, matches, pattern)) {
        hour_str = matches[1];
        unsigned int h;
        minimaltimedifference::FromString(hour_str, h);

        minutes_str = matches[2];
        unsigned int m;
        minimaltimedifference::FromString(minutes_str, m);

        min_count=h*60;
        min=m;
    }
    return min_count+min;
}

unsigned int minimaltimedifference::MinimalTimeDifference(std::vector<std::string> times) {
    unsigned int min=20000,min2=0;

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