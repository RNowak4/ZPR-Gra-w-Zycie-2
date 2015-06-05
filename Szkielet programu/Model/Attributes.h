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
#include "SituationTraits.h"
#include <chrono>
#include <random>
#include <vector>

/* Zwykle atrybuty jednostki. To beda te bazowe, jak i tmp*/
class Attributes: public Trait {
private:
    // Funkcja, ktora generuje atrybuty zupelnie losowo, bez przodkow
    // Wywolana, gdy vector atrybutow jest pusty
    void generateAttributes();
    
public:
    Attributes();
    Attributes(const Attributes&);
    // Przekopiowanie atrybutow
    Attributes& operator=(const Attributes&);
    virtual ~Attributes();
    // Funkcja, ktora generuje atrybuty na podstawie przodkow
    void inheritAttributes(const Trait&, const Trait&,
              const std::vector<Trait>&, const std::vector<Trait>&);
};

#endif	/* ATTRIBUTES_H */