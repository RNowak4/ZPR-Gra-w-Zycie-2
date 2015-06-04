/*
 * CarnivoreSleeping.cpp
 *
 *  Created on: 27 maj 2015
 *      Author: radek
 */

#include "CarnivoreSleeping.h"

#include "../Animal.h"
#include "../Attributes.h"
#include "../Model.h"
#include "../ViewStructs.h"
#include "CarnivoreRandomWalking.h"
#include "Hunting.h"

class Animal;

CarnivoreSleeping::CarnivoreSleeping(Animal* animalPtr_) :
		CarnivoreAction(animalPtr_) {
	animalPtr->setVelocity(0.0);
	animalPtr->stopTurning();
	animalPtr->setAcceleration(0.0);
	animalPtr->returnLocationData()->sightLen_ -= decreaseValue;
}

CarnivoreSleeping::~CarnivoreSleeping() {
	animalPtr->returnLocationData()->sightLen_ += decreaseValue;
	modelPtr->deleteAction(this);
}

void CarnivoreSleeping::performAction() {
	animalPtr->getAttributes().sleepNeed_ -= 0.05;
}

Action* CarnivoreSleeping::chooseNextAction() {
	if (animalPtr->getAttributes().eatNeed_ > 6.0) {
		return new Hunting(animalPtr);
	}

	if (animalPtr->getAttributes().sleepNeed_ < 1.5) {
		return new CarnivoreRandomWalking(animalPtr);
	}

	return this;
}

void CarnivoreSleeping::deleteAnimal(const Animal*) {
	// nothing to do about that
}
