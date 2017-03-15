//
// Created by hushmans on 09.03.17.
//

#include <iostream>
#include <fstream>
#include "Polybius.h"
using namespace std;


int main(int argc, char* argv[]){
    ofstream output_file (argv[2], ios_base::in | ios_base::trunc);
    ifstream input_file (argv[1]);
    if(!output_file)
        cout << "Błąd pliku wyjściowego!" << endl;
    if(!input_file)
        cout <<"Błąd pliku wejściowego!" << endl;

    if(argc!=4) std::cout<<"Zla ilosc parametrow";
    else {
        if (*argv[3]==1){
            std::string message;
            input_file>>message;
            output_file<<PolybiusCrypt(message);
            std::cout<<"Wiadomosc zapisana do pliku ";
        }
        else {
            if(*argv[3]==0){
                std::string crypted;
                input_file>>crypted;
                output_file<<PolybiusDecrypt(crypted);
                std::cout<<"Wiadomosc zapisana do pliku ";
            }
            else std::cout<<"Błąd";
        }
    }
    output_file.close();
    input_file.close();
    return 0;
}
