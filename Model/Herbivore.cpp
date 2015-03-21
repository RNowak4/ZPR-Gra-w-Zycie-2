/* 
 * File:   Herbivore.cpp
 * Author: Radek
 * 
 * Created on 9 marca 2015, 21:30
 */

#include "Herbivore.h"

Herbivore::Herbivore() {
}

Herbivore::Herbivore(double x, double y):Animal(x,y) {
    
}

Herbivore::Herbivore(const Animal* father, const Animal* mother):
                        Animal(father,mother) {
}

Herbivore::Herbivore(const Herbivore& orig) {
}

Herbivore::~Herbivore() {
}

void Herbivore::updateStatus() {
}

void Herbivore::doMove() {
}