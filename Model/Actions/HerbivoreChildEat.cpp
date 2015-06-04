/*
 * HerbivoreChildEat.cpp
 *
 *  Created on: 4 cze 2015
 *      Author: radek
 */

#include "HerbivoreChildEat.h"

#include "../Animal.h"
#include "../Attributes.h"
#include "../Constants.h"
#include "../Model.h"
#include "../ViewStructs.h"
#include "Fleeing.h"
#include "FollowMother.h"

HerbivoreChildEat::HerbivoreChildEat(Animal* animalPtr_, Animal* motherPtr_) :
		ChildAction(animalPtr_, motherPtr_) {
	animalPtr->setVelocity(0.0);
	animalPtr->setAcceleration(0.0);
	animalPtr->stopTurning();
	animalPtr->returnLocationData()->sightLen_ /=
			Constants::DEFAULT_HERBIVORE_EATING_SIGHT_REDUCTION;
}

HerbivoreChildEat::~HerbivoreChildEat() {
	animalPtr->returnLocationData()->sightLen_ *=
			Constants::DEFAULT_HERBIVORE_EATING_SIGHT_REDUCTION;
	modelPtr->deleteAction(this);
}

void HerbivoreChildEat::performAction() {
	animalPtr->getAttributes().eatNeed_ -= 0.07;
}

Action* HerbivoreChildEat::chooseNextAction() {
	auto animalsVector = modelPtr->getNearlyAnimals(
			animalPtr->returnLocationData()->coordinates_,
			animalPtr->getAttributes().hearingRange_);

	for (auto animal : animalsVector) {
		if (animalPtr->isDangerous(animal)) {
			return new Fleeing(animalPtr, animal);
		}
	}

	if (animalPtr->getAttributes().eatNeed_ < 2.5) {
		return new FollowMother(animalPtr, motherPtr);
	}

	return this;
}

void HerbivoreChildEat::deleteAnimal(const Animal*) {
	// nothing to do about that
}
