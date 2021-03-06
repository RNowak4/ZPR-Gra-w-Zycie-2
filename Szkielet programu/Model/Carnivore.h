/* 
 * File:   Carnivore.h
 * Author: Radek
 *
 * Created on 9 marca 2015, 21:32
 */

#ifndef CARNIVORE_H
#define	CARNIVORE_H

#include "Animal.h"

/*-Podczas poscigu zwierze powinno moc zmienic cel
 * na slabszy, jesli taki napotka na swojej drodze.
 */

class Carnivore: public Animal {
public:
    Carnivore();
    Carnivore(unsigned, unsigned);
    Carnivore(const Carnivore& orig);
    virtual ~Carnivore();
    virtual void updateStatus();
    virtual void doMove();
    virtual bool isDangerous() { return true; } //nie zawsze bedzie true
    
private:

};

#endif	/* CARNIVORE_H */