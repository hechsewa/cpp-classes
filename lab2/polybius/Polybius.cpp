//
// Created by hushmans on 09.03.17.
//

#include "Polybius.h"
#define toDigit(c) (c-'0'-1)


std::string PolybiusCrypt(std::string message){
    std::string encrypted;
    std::ostringstream oss;
    std::transform(message.begin(), message.end(), message.begin(), ::tolower);
    std::map <char, unsigned int> pb = {{'a',11}, {'b',12}, {'c',13}, {'d',14}, {'e',15},
                         {'f',21}, {'g',22}, {'h',23}, {'i',24}, {'j',24}, {'k',25},
                         {'l',31}, {'m',32}, {'n',33}, {'o',34}, {'p',35},
                         {'q',41}, {'r',42}, {'s',43}, {'t',44}, {'u',45},
                         {'v',51}, {'w',52}, {'x',53}, {'y',54}, {'z',55}};
    for (int i=0; i < message.length(); ++i){
        if (message[i]!=' '){
            oss<<pb[message[i]];
            encrypted = oss.str();
        }
    }
    return encrypted;
}

std::string PolybiusDecrypt(std::string crypted){
    std::string decrypted;
    char array[5][5] = {
            {'A', 'B', 'C', 'D', 'E'},
            {'F', 'G', 'H', 'I', 'K'},
            {'L', 'M', 'N', 'O', 'P'},
            {'Q', 'R', 'S', 'T', 'U'},
            {'V', 'W', 'X', 'Y', 'Z'}};

    for(int i=0; i < crypted.size(); i+=2) {
        decrypted += array[toDigit(crypted[i])][toDigit(crypted[i + 1])];
    }

    std::transform(decrypted.begin(), decrypted.end(), decrypted.begin(), ::tolower);
    return decrypted;
}