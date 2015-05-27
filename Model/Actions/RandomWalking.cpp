/*
 * RandomWalking.cpp
 *
 *  Created on: 21 maj 2015
 *      Author: radek
 */

#include "RandomWalking.h"

#include "../Animal.h"
#include "../Attributes.h"
#include "../Model.h"
#include "../ViewStructs.h"
#include "CarnivoreSleeping.h"
#include "Hunting.h"

RandomWalking::RandomWalking(Animal* animalPtr_) :
		CarnivoreAction(animalPtr_) {
	animalPtr->setLookingAngle(0);
	animalPtr->setVelocity(0.7);
	animalPtr->setAcceleration(0.0);
	animalPtr->turnRight();
}

RandomWalking::~RandomWalking() {
	modelPtr->deleteAction(this);
}

void RandomWalking::performAction() {
	// nothing to do
}

Action* RandomWalking::chooseNextAction() {
	auto animalVector = modelPtr->getAnimalsInSight(
			animalPtr->returnCoodtinates(),
			animalPtr->returnLocationData()->sightLen_,
			animalPtr->returnLocationData()->lookingAngle,
			animalPtr->returnLocationData()->lookingRad);

	for (auto animal : animalVector) {
		if (animalPtr->getAttributes().eatNeed_ <= 7.0)
			break;
		if (animal->isHerbivore()) {
			return new Hunting(animalPtr, animal);
		}
	}

	if (animalPtr->getAttributes().sleepNeed_ > 8.0)
		return new CarnivoreSleeping(animalPtr);

	return this;
}
