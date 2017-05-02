//
// Created by Student on 06/04/17.
//

#ifndef JIMP_EXERCISES_STUDYYEAR_H
#define JIMP_EXERCISES_STUDYYEAR_H

#include <iostream>

namespace academia {
    class StudyYear {
    public:
        StudyYear(): studyyear_(1) {};
        StudyYear(int syear): studyyear_(syear) {};
        int GetYear() const;
        //zdefiniować operator ++ i -- pre(in|de)krementacji dla StudyYear

        StudyYear &operator++();
        StudyYear operator++(int);

    private:
        int studyyear_;

    };

}


#endif //JIMP_EXERCISES_STUDYYEAR_H
