//
// Created by Student on 30/03/17.
//

#include "XXX.h"

XXX::XXX() : name_{new char[1024]} {
}

//destruktor
XXX::~XXX() {
    delete [] name_;
}

//konstruktor kopiujacy
XXX::XXX(const XXX& xxx) {
    size_t sz = strlen(xxx.name_);
    name_ = new char[sz];
    strcpy(name_,xxx.name_);
}

//operator przypisania:
XXX & XXX::operator=(const XXX& xxx) {
    if (this == &xxx) {
        return *this;
    }

    delete[] name_;
    size_t sz = strlen(xxx.name_);
    name_ = new char[sz];
    strcpy(name_,xxx.name_);
}


//konstruktor przenoszacy
XXX::XXX(XXX &&xxx) : name_{nullptr} {
swap(name_,xxx.name_);

}

//operator przenoszący:
XXX & XXX::operator=(XXX &&xxx) {
    //jeśli ktoś wpadł na pomsył x = move(x);
    if (this == &xxx) {
        return xxx;
    }

    delete[] name_;
    name_ = nullptr;
    swap(name_,xxx.name_);
}