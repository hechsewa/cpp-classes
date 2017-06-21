
#include "PointO.h"
#include <iostream>

using namespace std;

int main(){
    Point a,b;
    a.SetX(16);
    a.SetY(22);
    b.SetY(2);
    cout<<a<<endl<<b;
    Point c;
    cout << "Podaj punkt c w formacie (x,y):" <<endl;
    cin >> c;
    cout << "Twój punkt c to: " << c;
}