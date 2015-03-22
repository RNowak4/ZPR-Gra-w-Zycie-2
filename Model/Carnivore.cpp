/* 
 * File:   Carnivore.cpp
 * Author: Radek
 * 
 * Created on 9 marca 2015, 21:32
 */

#include "Carnivore.h"

Carnivore::Carnivore() {
}

Carnivore::Carnivore(unsigned x, unsigned y): Animal(x,y) {
    locationData_.animalType_ = CARNIVORE;
}

Carnivore::Carnivore(const Carnivore& orig) {
}

Carnivore::~Carnivore() {
}

void Carnivore::updateStatus() {
}

void Carnivore::doMove() {
}