/* 
 * File:   Animal.h
 * Author: Radek
 *
 * Created on 9 marca 2015, 21:29
 */
//test
#ifndef ANIMAL_H
#define	ANIMAL_H

#include <vector>
#include "Attributes.h"

class Attributes;

class Animal {
public:
    struct Coordinates {
        double x,y;
        // Tymczasowo, zeby nie wywalalo errorow
        Coordinates() { }
        Coordinates(double X, double Y) : x(X), y(Y) { }
    };

    enum Sex {
        FEMALE,
        MALE
    };
    
    struct LocationData {
        Coordinates coordinates_;
        // Zmienna, ktora okresla, gdzie patrzy dana jednostka
        double whareLooking_;
        // Zmienna, ktora okresla kat widzenia
        double lookingRad_;
        // Zmienna, ktora okresla zasieg widzenia
        double sightLen_;
    };

private:
    // Atrybuty bazowe dla jednostki(te beda dziedziczone)
    Attributes baseAttributes_;
    // Atrybuty w danej chwili
    Attributes tmpAttributes_;
    std::vector<Trait> ancestorsTraits_;
    // Cechy. W sensie bierne atrybuty
//   std::vector<const SituationTraits*> traits_;
    Sex sex_;
    LocationData locationData_;
    
protected:
    
public:
    // Tymczasowo, zeby nie wywalalo errorow
    Animal() { };
    Animal(const Animal& orig); 
    Animal(double, double);
    Animal(const Animal*, const Animal*);
    // Za bardzo nie ma czego usuwac, wiec pusty destruktor
    // Usuwaniem z ekranu zajmuje sie Cotroller.
    virtual ~Animal() { }
    // Aktualizuje status jednostki
    virtual void updateStatus() = 0;
    // Porusz sie
    virtual void doMove() = 0;
    // Zwraca wspolrzedne(do wyswietlania przez V)
    Coordinates returnCoodtinates() const { return locationData_.coordinates_; }
    const Attributes& getBaseAttributes() const { return baseAttributes_; }
    const std::vector<Trait>& getAncestorTraits() const { return ancestorsTraits_; }
    const LocationData& returnLocationData() const { return locationData_; }
    //Funkcja sprawdza, czy zwierze jest niebezpieczne
    virtual bool isDangerous() = 0;
};

#endif	/* ANIMAL_H */
