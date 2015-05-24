/*
 * Eating.cpp
 *
 *  Created on: 24 maj 2015
 *      Author: radek
 */

#include "Eating.h"

#include "../Animal.h"
#include "../Model.h"
#include "../ViewStructs.h"

Eating::Eating(Animal* animalPtr_) :
		Action(animalPtr_) {
	animalPtr->setVelocity(0.0);
	animalPtr->returnLocationData()->sightLen_ -= decreaseValue;
}

Eating::~Eating() {
	animalPtr->returnLocationData()->sightLen_ += decreaseValue;
	modelPtr->deleteAction(this);
}

void Eating::performAction() {
	//TODO zwiekszanie wyspania
	// Jesli zobaczy atakujacego carnivore, to spierdala
}

Action* Eating::chooseNextAction() {
	//TODO dodac, ze jak sie wyspi to cos tam
	return this;
}

void Eating::deleteAnimal(const Animal*) {
	// nothing to do about that
}
