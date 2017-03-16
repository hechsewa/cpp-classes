//
// Created by Student on 16/03/17.
//

#include <vector>
#include <sstream>
#include <regex>
#include <cmath>
#include "MinimalTimeDifference.h"

unsigned int ToMinutes(std::string time_HH_MM) {
    int hour, min;
    std::string string_h, string_m;

    std::regex pattern{R "((/d{1,2}):(/d{2}))" };
    std::string line (time_HH_MM);
    std::smatch matches;
    if (regex_match(line, matches, pattern)) {
        string_h = matches[1];
        int h;
        std::istringstream iss(string_h);
        iss >> h;

        string_m = matches[2];
        int m;
        std::istringstream iss(string_m);
        iss >> m;

        hour=h*60;
        min=m;
    }
    return hour+min;
}

unsigned int MinimalTimeDifference(std::vector<std::string> times) {
    int max=2000, min=0;


}