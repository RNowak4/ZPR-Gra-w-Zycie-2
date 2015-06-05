/*
 * Sleeping.cpp
 *
 *  Created on: 24 maj 2015
 *      Author: radek
 */

#include "Sleeping.h"

#include "../Animal.h"
#include "../Attributes.h"
#include "../Model.h"
#include "../ViewStructs.h"
#include "Eating.h"
#include "Fleeing.h"
#include "HerbivoreRandomWalking.h"

class Animal;

Sleeping::Sleeping(Animal* animal_ptr) :
		Action(animal_ptr) {
	animalPtr->setVelocity(0.0);
	animalPtr->stopTurning();
	animalPtr->setAcceleration(0.0);
	animalPtr->returnLocationData()->sightLen_ -= decreaseValue;
}

Sleeping::~Sleeping() {
	animalPtr->returnLocationData()->sightLen_ += decreaseValue;
	modelPtr->deleteAction(this);
}

void Sleeping::performAction() {
	animalPtr->returnSleepNeed() -= 0.2;
}

Action* Sleeping::chooseNextAction() {
	auto animalsVector = modelPtr->getNearlyAnimals(
			animalPtr->returnLocationData()->coordinates_,
			animalPtr->getAttributes().hearingRange_);

	for (auto animal : animalsVector) {
		if (animalPtr->isDangerous(animal)) {
			return new Fleeing(animalPtr, animal);
		}
	}

	if (animalPtr->returnEatNeed() > 6.0) {
		return new Eating(animalPtr);
	}

	if (animalPtr->returnSleepNeed() < 1.5) {
		return new HerbivoreRandomWalking(animalPtr);
	}

	return this;
}

void Sleeping::deleteAnimal(const Animal*) {
	// nothing to do about that
}
