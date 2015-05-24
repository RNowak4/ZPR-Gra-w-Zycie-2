/*
 * Sleeping.cpp
 *
 *  Created on: 24 maj 2015
 *      Author: radek
 */

#include "Sleeping.h"

#include "../Animal.h"
#include "../Model.h"
#include "../ViewStructs.h"

class Animal;

Sleeping::Sleeping(Animal* animalPtr_) :
		Action(animalPtr_) {
	animalPtr->setVelocity(0.0);
	animalPtr->returnLocationData()->sightLen_ -= decreaseValue;
}

Sleeping::~Sleeping() {
	animalPtr->returnLocationData()->sightLen_ += decreaseValue;
	modelPtr->deleteAction(this);
}

void Sleeping::performAction() {
	//TODO zwiekszanie wyspania
	// Jesli "zobaczy"(wiem ze spi ale to uproszczenie)
	// atakujacego carnivore, to spierdala
}

Action* Sleeping::chooseNextAction() {
	//TODO dodac, ze jak sie wyspi to cos tam
}

void Sleeping::deleteAnimal(const Animal*) {
	// nothing to do about that
}
