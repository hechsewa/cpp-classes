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
        double Circumference();
        double Area();
        Square(Point p1, Point p2, Point p3, Point p4);

    private:
        Point vertices[4];

    };

};


#endif //JIMP_EXERCISES_SQUARE_H
