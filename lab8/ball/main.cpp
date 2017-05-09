#include <iostream>
#include "Ball.h"

int main(){
    try{
        drawBall();
    }catch(const BallException &b){
        cout << "Blad podczas rysowania kuli" << endl;
    }catch(CircleException a) {
        cout << "Blad podczas rysowania kola" << endl;
    }
}