/* 
 * File:   Animal.h
 * Author: Radek
 *
 * Created on 9 marca 2015, 21:29
 */

#ifndef ANIMAL_H
#define	ANIMAL_H

#include <vector>
#include "Attributes.h"

class Attributes;

struct Coordinates{
    double x,y;
    // Tymczasowo, zeby nie wywalalo errorow
    Coordinates() { }
    Coordinates(double X, double Y) : x(X), y(Y) { }
};

/* Zrobic klase atrybutow!
 */
class Animal {
private:
    Attributes attributes_;
    std::vector<Attributes> ancestorAttributes;
    Coordinates coordinates_;
    
protected:
    // Pobiera Wspolrzedne widzianego zwierzeta
    Coordinates getCoordinates(const Animal*) const;
    // Zwraca liste z widzianymi zwierzetami
    std::vector<const Animal*> getAnimalsInSight() const;
    
public:
    // Tymczasowo, zeby nie wywalalo errorow
    Animal() { };
    // Animal bedzie przyjmowalo okreslone wartosci srednie i odchylenia std
    // Przy powolaniu do zycia. Nastepnie z nich wygeneruje
    // Wartosci losowe zgodnie z rozkladem gaussa.
    //!! Ogolnie mysle, ze takie wartosci ogolne powinny byc stale
    // i dopiero atrybuty by je modyfikowaly
//    Animal(...);
    // Zadnego klonowania. To wbrew naturze, barbarzynco.
    // W sumie klonowanie moze sie przydac przy kopiowaniu calego modelu
    Animal(const Animal& orig) = delete; 
    // Za bardzo nie ma czego usuwac, wiec pusty destruktor
    // Usuwaniem z ekranu zajmuje sie Cotroller.
    virtual ~Animal() { }
    // Aktualizuje status jednostki
    virtual void updatetatus() = 0;
    // Zwraca wspolrzedne(do wyswietlania przez V)
    Coordinates returnCoodtinates() const { return coordinates_; }
};

#endif	/* ANIMAL_H */