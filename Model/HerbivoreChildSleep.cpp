/*
 * HerbivoreChildSleep.cpp
 *
 *  Created on: 4 cze 2015
 *      Author: radek
 */

#include "HerbivoreChildSleep.h"

#include "Actions/Fleeing.h"
#include "Actions/FollowMother.h"
#include "Actions/HerbivoreChildEat.h"
#include "Animal.h"
#include "Attributes.h"
#include "Constants.h"
#include "Model.h"
#include "ViewStructs.h"

HerbivoreChildSleep::HerbivoreChildSleep(Animal* animalPtr_, Animal* motherPtr_) :
		ChildAction(animalPtr_, motherPtr_) {
	animalPtr->setVelocity(0.0);
	animalPtr->stopTurning();
	animalPtr->setAcceleration(0.0);
	animalPtr->returnLocationData()->sightLen_ /=
			Constants::DEFAULT_HERBIVORE_SLEEPING_SIGHT_REDUCTION;
}

HerbivoreChildSleep::~HerbivoreChildSleep() {
	animalPtr->returnLocationData()->sightLen_ *=
			Constants::DEFAULT_HERBIVORE_SLEEPING_SIGHT_REDUCTION;
	modelPtr->deleteAction(this);
}

void HerbivoreChildSleep::performAction() {
	animalPtr->getAttributes().sleepNeed_ -= 0.05;
}

Action* HerbivoreChildSleep::chooseNextAction() {
	auto animalsVector = modelPtr->getNearlyAnimals(
			animalPtr->returnLocationData()->coordinates_,
			animalPtr->getAttributes().hearingRange_);
	if (animalPtr->returnLocationData()->animalType_ == HERBIVORE_CHILD) {
		for (auto animal : animalsVector) {
			if (animalPtr->isDangerous(animal)) {
				return new Fleeing(animalPtr, animal);
			}
		}
	}

	if (animalPtr->returnLocationData()->animalType_ == HERBIVORE_CHILD
			&& animalPtr->getAttributes().eatNeed_ > 6.0) {
		return new HerbivoreChildEat(animalPtr, motherPtr);
	}

	if (animalPtr->getAttributes().sleepNeed_ < 1.5) {
		return new FollowMother(animalPtr, motherPtr);
	}

	return this;
}

void HerbivoreChildSleep::deleteAnimal(const Animal*) {
	// nothing to do about that
}
