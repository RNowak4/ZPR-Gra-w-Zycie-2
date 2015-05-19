/* 
 * File:   Herbivore.cpp
 * Author: Radek
 * 
 * Created on 9 marca 2015, 21:30
 */

#include "Herbivore.h"

Herbivore::Herbivore(unsigned x, unsigned y) :
		Animal(x, y) {
	locationData_.animalType_ = HERBIVORE;
}
/*
 Herbivore::Herbivore(const Herbivore& orig) {
 }*/

Herbivore::~Herbivore() {
}

Herbivore::Herbivore(unsigned x, unsigned y, const Modifiers& modifiers) :
		Animal(x, y, modifiers, CARNIVORE) {
}
