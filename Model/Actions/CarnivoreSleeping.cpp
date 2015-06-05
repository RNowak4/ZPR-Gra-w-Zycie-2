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

CarnivoreSleeping::CarnivoreSleeping(Animal* animal_ptr) :
		CarnivoreAction(animal_ptr) {
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
	animalPtr->returnSleepNeed() -= 0.2;
}

Action* CarnivoreSleeping::chooseNextAction() {
	if (animalPtr->returnEatNeed() > 6.0) {
		return new Hunting(animalPtr);
	}

	if (animalPtr->returnSleepNeed() <= 2)
		return new CarnivoreRandomWalking(animalPtr);


	if (animalPtr->returnEatNeed() < 1.5) {
		return new CarnivoreRandomWalking(animalPtr);
	}

	if (animalPtr->returnSleepNeed() <= 2)
		return new CarnivoreRandomWalking(animalPtr);

	return this;
}

void CarnivoreSleeping::deleteAnimal(const Animal*) {
	// nothing to do about that
}
