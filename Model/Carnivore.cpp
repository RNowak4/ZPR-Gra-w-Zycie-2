/* 
 * File:   Carnivore.cpp
 * Author: Radek
 * 
 * Created on 9 marca 2015, 21:32
 */

#include "Carnivore.h"

#include "ViewStructs.h"

Carnivore::Carnivore(unsigned x, unsigned y) :
		Animal(x, y, CARNIVORE) {
}
/*
 Carnivore::Carnivore(const Carnivore& orig) {
 }*/

Carnivore::~Carnivore() {
}

Carnivore::Carnivore(unsigned x, unsigned y, const Modifiers& modifiers) :
		Animal(x, y, modifiers, CARNIVORE) {
}
