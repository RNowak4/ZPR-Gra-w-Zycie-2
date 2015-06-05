/**
* @file Childhood.cpp
* @brief Implementation of the Childhood class
*
* @author Radoslaw Nowak
*/


#include "Childhood.h"

#include "../Animal.h"
#include "../Attributes.h"

Childhood::Childhood(Animal* animal_ptr, Animal* mother_ptr) :
		State(animal_ptr), mother(mother_ptr) {
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
	mother->deleteChild(animalPtr);
}

string Childhood::toString() {
	return string("Childhood");
}

bool Childhood::isThatMe(string state_name) {
	if (state_name == "Childhood")
		return true;
	return false;
}
