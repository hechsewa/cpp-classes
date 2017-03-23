//
// Created by Student on 23/03/17.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include "Point.h"

namespace geometry {
    using ::std::ostream;
    using ::std::endl;
    using ::std::pow;
    using ::std::sqrt;

    class Square {
    public:
        Square(Point, Point);
        double Circumference();
        double Area;

    private:
        Point x_;
        Point y_;
        Point z_;
        Point h_;

    };
}


#endif //JIMP_EXERCISES_SQUARE_H
