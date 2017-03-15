//
// Created by hushmans on 15.03.17.
//

#ifndef CCOUNTER_H
#define CCOUNTER_H

#include <string>
#include <memory>
#include <map>

namespace Counter {
    std::unique_ptr<Counter> Init(); //stworzenie i zainicjowanie obiektu
    void Inc(std::string key, std::unique_ptr<Counter>* counter); //zwiekszenie licznika obiektu o 1
    int Counts(const std::unique_ptr<Counter> &counter, std::string key); //zwraca aktualny licznik obiektow
    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter); //ustawienie licznika na zadana wartosc
};


#endif //CCOUNTER_H
