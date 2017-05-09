//
// Created by Student on 27/04/17.
//

#ifndef JIMP_EXERCISES_BALL_H
#define JIMP_EXERCISES_BALL_H

#include <iostream>
using namespace std;

class CircleException{
    // Oznacza ze nie mozna wyrysowac kola
};

class BallException : public CircleException{

    // Oznacza ze nie mozna wyrysowac kuli
};

void drawBall();

#endif //JIMP_EXERCISES_BALL_H
