//
// Created by Student on 06/04/17.
//

#include "StudyYear.h"

namespace academia {

    int StudyYear::GetYear() const {
        return studyyear_;
    }

    StudyYear &StudyYear::operator++(){
        ++studyyear_;
    }
    StudyYear StudyYear::operator++(int){
        studyyear_++;
    }

}
