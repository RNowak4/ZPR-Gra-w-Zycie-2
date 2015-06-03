/*
 * Illness.cpp
 *
 *  Created on: 17-05-2015
 *      Author: radek
 */

#include "Illness.h"

#include "../Animal.h"
#include "../Attributes.h"

Illness::Illness(Animal* animalPtr_) :
		State(animalPtr_) {
	animalPtr_->getAttributes().strength_ -= 4.0;
	animalPtr_->getAttributes().lifeLen_ -= 100;
}

Illness::~Illness() {
	animalPtr->getAttributes().strength_ += 4.0;
	animalPtr->getAttributes().lifeLen_ += 100;
}

string Illness::toString() {
	return string("Illness");
}
