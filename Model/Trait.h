/* 
 * File:   Trait.h
 * Author: Radek
 *
 * Created on 12 marca 2015, 02:12
 */

#ifndef TRAIT_H
#define	TRAIT_H

/* Struktura przechowujaca modyfikatory do atrybutow
 * TODO: funkcje zwracajace strukture;
 */

class Trait {
public:
    struct Modifiers {
        double anger_;
        double needForSleep_;
        double strength_;
        double speed_;
        double fertility_; 
        double hunger_; 
        double sightLen_;
        unsigned lifeLen_; 
        unsigned sightRad_;
    };
    
protected:
    Modifiers modifiers_;
    
public:
    Trait() { }
    Trait(double anger,double needForSleep,double strength, double speed,
          double fertility, double hunger, double sightLen, unsigned lifeLen,
          unsigned sightRad) {
        modifiers_.anger_ = anger;
        modifiers_.needForSleep_ = needForSleep; 
        modifiers_.strength_ = strength;
        modifiers_.speed_ = speed;
        modifiers_.fertility_ = fertility; 
        modifiers_.hunger_ = hunger;
        modifiers_.sightLen_ = sightLen; 
        modifiers_.lifeLen_ = lifeLen;
        modifiers_.sightRad_ = sightRad;
    }
    const Modifiers& returnModifiers() const { return modifiers_; }
};

#endif	/* TRAIT_H */

