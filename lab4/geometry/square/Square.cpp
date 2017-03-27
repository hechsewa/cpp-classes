//
// Created by hushmans on 26.03.17.
//

#include "Square.h"

Square::Square(Point p1, Point p2, Point p3, Point p4) {
    this->vertices[0] = p1;
    this->vertices[1] = p2;
    this->vertices[2] = p3;
    this->vertices[3] = p4;
}

double Square::Circumference() {
    return 4*this->vertices[0].Distance(this->vertices[1]);
}

double Square::Area() {
    return this->vertices[0].Distance(this->vertices[1]) * this->vertices[0].Distance(this->vertices[1]);
}