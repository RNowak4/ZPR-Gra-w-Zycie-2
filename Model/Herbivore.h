/* 
 * File:   Herbivore.h
 * Author: Radek
 *
 * Created on 9 marca 2015, 21:30
 */

#ifndef HERBIVORE_H
#define	HERBIVORE_H

#include "Animal.h"

class Herbivore: public Animal {
private:
    
public:
    Herbivore();
    Herbivore(unsigned, unsigned);
    Herbivore(const Animal*, const Animal*);
    Herbivore(const Herbivore& orig);
    virtual ~Herbivore();
    virtual void updateStatus();
    virtual void doMove();
    virtual bool isDangerous() { return false; }
};

#endif	/* HERBIVORE_H */

