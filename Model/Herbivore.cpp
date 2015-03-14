/* 
 * File:   Herbivore.cpp
 * Author: Radek
 * 
 * Created on 9 marca 2015, 21:30
 */

#include "Herbivore.h"

Herbivore::Herbivore() {
}

Herbivore::Herbivore(const Animal* father, const Animal* mother):
                        Animal(father,mother) {
}

Herbivore::Herbivore(const Herbivore& orig) {
}

Herbivore::~Herbivore() {
}

void Herbivore::updatetatus() {
}

void Herbivore::doMove() {
}