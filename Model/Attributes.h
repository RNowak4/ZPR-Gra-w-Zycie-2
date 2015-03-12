/* 
 * File:   Attributes.h
 * Author: Radek
 *
 * Created on 12 marca 2015, 00:37
 */

#ifndef ATTRIBUTES_H
#define	ATTRIBUTES_H

/* TODO:
 *-Kazda bierna cecha bedzie reprezentowana 
 * przez stala strukture Trait.
 * 
 *- Utworzyc nowa klase Trait dla cech. 
 */

#include "Trait.h"
#include <chrono>
#include <random>
#include <vector>

class Attributes {
private:
    double anger_;
    double needForSleep_;
    double strength_;
    double speed_;
    double fertility_; // Plodnosc
    double hunger_; 
    double sightLen_; // Jak daleko jednostka widzi = wys trojkata
    unsigned lifeLen_; // Dlugosc zycia wyrazona w ustalonych kwantach czasu
    // Kat widzenia
    unsigned sightRad_; 
    // Funkcja, ktora generuje atrybuty zupelnie losowo, bez przodkow
    // Wywolana, gdy vector atrybutow jest pusty
    void generateAttributes();
    
public:
    Attributes();
    Attributes(const Attributes&);
    virtual ~Attributes();
    // Funkcja, ktora generuje atrybuty na podstawie przodkow
    void inheritAttributes(std::vector<Attributes>);
    // Przekopiowanie atrybutow
    Attributes& operator=(const Attributes&);
    //Dodanie atrybutow do istniejacych
    Attributes& operator+(const Trait&) const;
};

#endif	/* ATTRIBUTES_H */