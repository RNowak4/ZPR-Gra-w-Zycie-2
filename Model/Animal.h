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

class Animal {
private:
    // Zmienna, ktora okresla, gdzie patrzy dana jednostka
    double lookingRad_;
    // Atrybuty bazowe dla jednostki(te beda dziedziczone)
    Attributes baseAttributes_;
    // Atrybuty w danej chwili
    Attributes tmpAttributes_;
    std::vector<Attributes> ancestorsAttributes_;
    // Cechy. W sensie bierne atrybuty
    std::vector<const Trait*> traits_;
    Coordinates coordinates_;
    
protected:
    
public:
    // Tymczasowo, zeby nie wywalalo errorow
    Animal() { };
    Animal(const Animal& orig) = delete; 
    // Za bardzo nie ma czego usuwac, wiec pusty destruktor
    // Usuwaniem z ekranu zajmuje sie Cotroller.
    virtual ~Animal() { }
    // Aktualizuje status jednostki
    virtual void updatetatus() = 0;
    // Porusz sie
    virtual void doMove() = 0;
    // Zwraca wspolrzedne(do wyswietlania przez V)
    Coordinates returnCoodtinates() const { return coordinates_; }
    // Usuwa ceche, np potrzebe snu.
    void deleteTrait(const Trait*);
};

#endif	/* ANIMAL_H */