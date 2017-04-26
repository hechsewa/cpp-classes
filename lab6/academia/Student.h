//
// Created by Student on 06/04/17.
//

#ifndef JIMP_EXERCISES_STUDENT_H
#define JIMP_EXERCISES_STUDENT_H

#include "StudyYear.h"
#include <iostream>
using std::string;

namespace academia {

    class Student{
    public:
        Student();
        Student(string id, string first_name, string last_name, string program, int year);

        string Id()const;
        string FirstName()const;
        string LastName()const;
        string Program()const;
        StudyYear Year() const ;

    private:
        std::string id_, first_name_, last_name_, program_;
        StudyYear year_;
    };
}


#endif //JIMP_EXERCISES_STUDENT_H
