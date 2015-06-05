/*
 * Childhood.cpp
 *
 *  Created on: 17-05-2015
 *      Author: radek
 */

#include "Childhood.h"

#include "../Animal.h"
#include "../Attributes.h"

Childhood::Childhood(Animal* animalPtr_) :
		State(animalPtr_) {
	dec_values[0] = animalPtr->getAttributes().eatNeed_ * 0.5;
	dec_values[1] = animalPtr->getAttributes().maximalSpeed_ * 0.25;
	dec_values[2] = animalPtr->getAttributes().strength_ * 0.75;
	animalPtr->getAttributes().eatNeed_ *= 0.5;
	animalPtr->getAttributes().maximalSpeed_ *= 0.75;
	animalPtr->getAttributes().strength_ *= 0.25;
}

Childhood::~Childhood() {
	animalPtr->getAttributes().eatNeed_ += dec_values[0];
	animalPtr->getAttributes().maximalSpeed_ += dec_values[1];
	animalPtr->getAttributes().strength_ += dec_values[2];
}

string Childhood::toString() {
	return string("Childhood");
}

bool Childhood::isThatMe(string stateName) {
	if (stateName == "Childhood")
		return true;
	return false;
}
