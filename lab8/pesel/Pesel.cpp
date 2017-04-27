//
// Created by Student on 27/04/17.
//

#include "Pesel.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>

string Pesel::GetPesel() const{
    return pesel_no_;
}

void Pesel::SetPesel(string pesel){
    pesel_no_ = pesel;
}

void Pesel::validatePESEL(const char* pesel){
    if (strlen(pesel) == 11) {
        double control_no = 9*pesel[0]+7*pesel[1]+3*pesel[2]+1*pesel[3]+9*pesel[4]+7*pesel[5]+3*pesel[6]+1*pesel[7]+9*pesel[8]+7*pesel[9];
        std::ostringstream strs;
        strs << control_no;
        std::string str_cn = strs.str();
        std::string lastchar_control_no = str_cn.substr(-1);
        if (lastchar_control_no != pesel[10]){
            cout <<"Bledny pesel"<<endl;
        }
    }
    else {
        cout << "Bledna dlugosc peselu"<<endl;
    }

}
