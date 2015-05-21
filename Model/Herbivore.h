/**
 * @file Herbivore.cpp
 * @brief A class that represents a Herbivore
 *
 * @author Radoslaw Nowak
 */

#ifndef HERBIVORE_H
#define	HERBIVORE_H

#include "Animal.h"

class Herbivore: public Animal {
private:
    
public:
    Herbivore();
    Herbivore(unsigned, unsigned);
    Herbivore(unsigned, unsigned, const Modifiers&);
    Herbivore(const Herbivore& orig);
    virtual ~Herbivore();
    virtual bool isDangerous(Animal* another) { return false; }
};

#endif	/* HERBIVORE_H */
