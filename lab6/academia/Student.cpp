//
// Created by Student on 06/04/17.
//

#include "Student.h"
#include "StudyYear.h"

using std::string;

namespace academia {
    Student::Student() {}

    Student::Student(string id, string first_name, string last_name, string program, int year) :
            id_(id),
            first_name_(first_name),
            last_name_(last_name),
            program_(program),
            year_(year) {}

    string Student::Id() const{ return id_; }
    string Student::FirstName() const{return first_name_;}
    string Student::LastName() const{return last_name_;}
    string Student::Program() const{return program;}
    StudyYear Student::Year() const{ return year_;}
}