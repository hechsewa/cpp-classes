//
// Created by Student on 16/03/17.
//

#include <vector>
#include <sstream>
#include <regex>
#include <cmath>
#include <iostream>
#include "MinimalTimeDifference.h"

using namespace std;
int main(){
    std::vector<std::string> times({"23:59", "00:00"});

    cout<<minimaltimedifference::MinimalTimeDifference(times);
    return 0;
}