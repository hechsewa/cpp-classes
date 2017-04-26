#include <iostream>
#include "Punkt3d.h"

/*
 * zad5.
 *  Klasa point3d dziedziczy po klasie point2d - klasa point3d jest "obudowana" klasą point 2d. Klasa point 2d
 *  w tym przypadku jest klasą bazową, dlatego najpierw wywołuje się konstruktor klasy point2d,
 *  potem konstruktor klasy point3d. Analogicznie, destruktor klasy point3d wywoła się po destruktorze klasy
 *  point 2d.
 *
 */
/*
 * zad6.
 *  Wywołanie punkt2d.Distance(punkt3d) zwróci niewymierną wartość, bo najpierw policzy dystans dla metody Distance
 *  klasy point3d, a potem przypisze wynik do obiektu klasy point2d, w efektcie zwracając dystans między punktami w
 *  2d.
 */
/*
 * zad7.
 *  Klasa point3d nie ma zdefiniowanego operatora "<<", więc przy jego wywołaniu wejdzie w grę klasa bazowa point2d,
 *  dla której już jest zdefiniowany operator "<<", dlatego wyświetli się tylko (1,2) jak w przypadku obiektu klasy
 *  point2d.
 */

using namespace geometry;

int main() {

    //Point punkt2d(16,2);
    //Punkt3d punkt3d(6,7,97);
    //std::cout<<"zadanie 6: "<<punkt2d.Distance(punkt3d)<<"\n";

    Punkt3d p3d(1, 2, 3);
    std::cout << p3d << std::endl;

    return 0;
}
