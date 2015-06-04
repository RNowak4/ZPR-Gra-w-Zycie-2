/*
 * Eating.cpp
 *
 *  Created on: 24 maj 2015
 *      Author: radek
 */

#include "Eating.h"

#include "../Animal.h"
#include "../Attributes.h"
#include "../Model.h"
#include "../ViewStructs.h"
#include "Fleeing.h"
#include "HerbivoreRandomWalking.h"

using namespace std;

Eating::Eating(Animal* animalPtr_) :
		Action(animalPtr_) {
	animalPtr->setVelocity(0.0);
	animalPtr->setAcceleration(0.0);
	animalPtr->stopTurning();
	animalPtr->returnLocationData()->sightLen_ -= decreaseValue;
}

Eating::~Eating() {
	animalPtr->returnLocationData()->sightLen_ += decreaseValue;
	modelPtr->deleteAction(this);
}

void Eating::performAction() {
	animalPtr->returnEatNeed() -= 0.2;
}

Action* Eating::chooseNextAction() {
	auto animalsVector = modelPtr->getNearlyAnimals(
			animalPtr->returnLocationData()->coordinates_,
			animalPtr->getAttributes().hearingRange_);

	for (auto animal : animalsVector) {
		if (animalPtr->isDangerous(animal)) {
			return new Fleeing(animalPtr, animal);
		}
	}

	if (animalPtr->returnEatNeed() < 2.5) {
		return new HerbivoreRandomWalking(animalPtr);
	}

	return this;
}

void Eating::deleteAnimal(const Animal*) {
	// nothing to do about that
}
