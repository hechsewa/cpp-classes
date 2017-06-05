//
// Created by hushmans on 03.06.17.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

/*Przygotować klasę Teacher, TeacherId i TeacherHash, klasa Teacher jest zwykłą klasą wartości,
 * TeacherId również (reprezentuje Id nauczyciela), natomiast TeacherHash to klasa/sturktura,
 * która jest obiektem wyliczającym skrót za pomocą przeciążonego operatora wywołania funkcji ().  */


#include <string>
#include <unordered_map>
#include<utility>

using namespace std;

namespace academia {

    class TeacherId {
    public:
        TeacherId(const int &id): id_(id){}
        TeacherId(const TeacherId &teacher):id_(teacher.id_){}
        operator int() const {return id_;}

        bool operator != (const TeacherId &teacher) const{
            return (teacher.id_!=id_); }

    private:
        size_t id_;

    };
    class Teacher{
    public:
        Teacher(const TeacherId &id, const string &name, const string &department):
                id_(id), name_(name), department_(department){}

        bool operator==(const Teacher &teacher) const {
            return (id_==teacher.id_ && name_==teacher.name_ && department_==teacher.department_); }
        bool operator != (const Teacher &teacher) const {
            return !(*this==teacher); }

        const int Id() const{return id_;}
        const string Name() const {return name_;}
        const string Department() const {return department_;}

    private:
        TeacherId id_;
        std::string name_;
        std::string department_;

    };

    /***hash *****/
    struct TeacherHash{
    public:
        size_t operator()(const Teacher &input) const {
            size_t name_result=0, department_result=0;
            for (auto &character : input.Name()){
                name_result += character;
            }

            for (auto &character : input.Department()){
                department_result += character;
            }

            return (input.Id() ^ name_result ^ department_result);
        }
    };
}


#endif //JIMP_EXERCISES_TEACHERHASH_H
