//
// Created by Student on 16/03/17.
//

#include <iostream>
#include "CCounter.h"

using namespace std;
int main(){
    std::unique_ptr<Counter> nowyObiekt = ccounter::Init();
    return 0;
}