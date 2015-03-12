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
    Herbivore(const Herbivore& orig);
    virtual ~Herbivore();
};

#endif	/* HERBIVORE_H */

