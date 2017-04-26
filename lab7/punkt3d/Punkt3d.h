//
// Created by hushmans on 26.04.17.
//

#ifndef JIMP_EXERCISES_PUNKT3D_H
#define JIMP_EXERCISES_PUNKT3D_H

#include "Punkt3d.h"
#include <Point.h>

namespace geometry {

    class Punkt3d : public Point{
    public:
        Punkt3d():Point(), z_(0) { std::cout<<"constructor point3d"<<endl; }
        Punkt3d(double x=0, double y=0, double z=0): Point(x,y), z_(z) { std::cout<<"constructor point3d 2"<<endl; }
        ~Punkt3d(){ std::cout<<"destructor point3d\n"; }

        double GetZ() const;
        void SetZ(double z);
        double Distance(const Punkt3d &other) const;

    private:
        double z_;
    };
}

#endif //JIMP_EXERCISES_PUNKT3D_H