/* 
 * File:   SituationTraits.h
 * Author: Radek
 *
 * Created on 15 marca 2015, 00:08
 */

#ifndef SITUATIONTRAITS_H
#define	SITUATIONTRAITS_H

#include "Trait.h"

/* Klasa czysto wirtualna. Po niej beda dziedziczyc randomowe cechy*/
class SituationTraits: public Trait {
public:
    SituationTraits();
    SituationTraits(const SituationTraits& orig);
    virtual ~SituationTraits();
private:

};

#endif	/* SITUATIONTRAITS_H */

