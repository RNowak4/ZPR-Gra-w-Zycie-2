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

class Animal {
public:
struct Coordinates{
    double x,y;
    // Tymczasowo, zeby nie wywalalo errorow
    Coordinates() { }
    Coordinates(double X, double Y) : x(X), y(Y) { }
};

enum Sex {
    FEMALE,
    MALE
};
    
private:
    // Zmienna, ktora okresla, gdzie patrzy dana jednostka
    double lookingRad_;
    // Atrybuty bazowe dla jednostki(te beda dziedziczone)
    Attributes baseAttributes_;
    // Atrybuty w danej chwili
    Attributes tmpAttributes_;
    std::vector<Attributes> ancestorsAttributes_;
    // Cechy. W sensie bierne atrybuty
<<<<<<< HEAD
//   std::vector<const SituationTraits*> traits_;
=======
   std::vector<const SituationTraits*> traits_;
>>>>>>> origin/master
    Coordinates coordinates_;
    Sex sex_;
    
protected:
    
public:
    // Tymczasowo, zeby nie wywalalo errorow
    Animal() { };
    Animal(const Animal& orig); 
    Animal(const Animal*, const Animal*);
    // Za bardzo nie ma czego usuwac, wiec pusty destruktor
    // Usuwaniem z ekranu zajmuje sie Cotroller.
    virtual ~Animal() { }
    // Aktualizuje status jednostki
    virtual void updateStatus() = 0;
    // Porusz sie
    virtual void doMove() = 0;
    // Zwraca wspolrzedne(do wyswietlania przez V)
    Coordinates returnCoodtinates() const { return coordinates_; }
    // Usuwa ceche, np potrzebe snu.
    void deleteTrait(const Trait*);
    const Attributes& getBaseAttributes() const { return baseAttributes_; }
    const std::vector<Attributes>& getAncestorAttributes() const { return ancestorsAttributes_; }
};

#endif	/* ANIMAL_H */
