/**
 * @file Carnivore.h
 * @brief Class that represents a Carnivore
 *
 * @author Radoslaw Nowak
 */

#ifndef CARNIVORE_H
#define	CARNIVORE_H

#include "Animal.h"

class Carnivore: public Animal {
public:
    Carnivore();
    Carnivore(unsigned, unsigned);
    Carnivore(unsigned, unsigned, const Modifiers&);
    Carnivore(const Carnivore& orig);
    virtual ~Carnivore();
    virtual bool isDangerous(Animal* another) { return true; } //nie zawsze bedzie true
    
private:

};

#endif	/* CARNIVORE_H */
