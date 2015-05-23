/*
 * RandomWalking.cpp
 *
 *  Created on: 21 maj 2015
 *      Author: radek
 */

#include "RandomWalking.h"

#include "../Animal.h"
#include "../Model.h"
#include "../ViewStructs.h"
#include "Follow.h"

RandomWalking::RandomWalking(Animal* animalPtr_) :
		CarnivoreAction(animalPtr_) {
	animalPtr_->setLookingAngle(0);
	animalPtr_->setVelocity(1.0);
	animalPtr_->turnRight();
}

RandomWalking::~RandomWalking() {
}

void RandomWalking::performAction() {
	//do nothing
}

Action* RandomWalking::chooseNextAction() {
	auto animalVector = modelPtr->getAnimalsInSight(
			animalPtr->returnCoodtinates(),
			animalPtr->returnLocationData()->sightLen_,
			animalPtr->returnLocationData()->lookingAngle,
			animalPtr->returnLocationData()->lookingRad);

	for (auto animal : animalVector) {
		if (animal->isHerbivore()) {
			return new Follow(animalPtr, animal);
		}
	}

	return this;
}
