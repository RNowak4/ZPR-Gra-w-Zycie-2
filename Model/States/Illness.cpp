/*
 * Illness.cpp
 *
 *  Created on: 17-05-2015
 *      Author: radek
 */

#include "Illness.h"

#include "../Animal.h"
#include "../Attributes.h"

Illness::Illness(Animal* animal_ptr) :
		State(animal_ptr) {
	animal_ptr->getAttributes().strength_ -= 4.0;
	animal_ptr->getAttributes().lifeLen_ -= 100;
}

Illness::~Illness() {
	animalPtr->getAttributes().strength_ += 4.0;
	animalPtr->getAttributes().lifeLen_ += 100;
}

string Illness::toString() {
	return string("Illness");
}
