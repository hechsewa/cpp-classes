//
// Created by Student on 27/04/17.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>
#include <iostream>
using namespace std;

class Pesel {
public:
    Pesel(): pesel_no_(0){}
    Pesel(std::string pesel): pesel_no_(pesel){} //konstruktor parametrynczny
    ~Pesel(){} //destruktor

    string GetPesel() const;
    void SetPesel(string pesel);

    void validatePESEL(const char* pesel);

private:
    string pesel_no_;
};


#endif //JIMP_EXERCISES_PESEL_H
