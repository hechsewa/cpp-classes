//
// Created by Student on 09/03/17.
//

#include <iostream>
#include "Array2D.h"

using namespace std;
int main(int argc, char* argv[]){
    int array_x, array_y;
    cout<<"podaj wymiary tablicy x, y:"<<endl;
    cin >> array_x >> array_y;
    int **DynamicArray;
    DynamicArray=NewArray2D(array_x,array_y);
    for(int i=0; i<array_x; i++) {
        for (int j = 0; j < array_y; j++) {
            cout << DynamicArray[i][j] << "\t";
        }
        cout << endl;
    }
    DeleteArray2D(DynamicArray, array_x, array_y);
    return 0;
}