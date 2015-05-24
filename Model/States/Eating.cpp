/*
 * Eating.cpp
 *
 *  Created on: 24 maj 2015
 *      Author: radek
 */

#include "Eating.h"

#include "../Animal.h"
#include "../ViewStructs.h"

Eating::Eating(Animal* animalPtr_) :
		State(animalPtr_) {
	animalPtr->returnLocationData()->sightLen_ -= decreaseValue;
}

Eating::~Eating() {
	animalPtr->returnLocationData()->sightLen_ += decreaseValue;
}

bool Eating::isThatMe(string stateName) {
	if (stateName == "Eating")
		return true;

	return false;
}

string Eating::toString() {
	return "Eating";
}
