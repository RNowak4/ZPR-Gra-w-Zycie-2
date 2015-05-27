/*
 * CarnivoreRandomWalking.cpp
 *
 *  Created on: 27 maj 2015
 *      Author: radek
 */

#include "CarnivoreRandomWalking.h"

#include "../Animal.h"
#include "../Attributes.h"
#include "../Model.h"
#include "../ViewStructs.h"
#include "CarnivoreSleeping.h"
#include "Hunting.h"

CarnivoreRandomWalking::CarnivoreRandomWalking(Animal* animalPtr_) :
		CarnivoreAction(animalPtr_) {
	animalPtr->setLookingAngle(0);
	animalPtr->setVelocity(0.7);
	animalPtr->setAcceleration(0.0);
	animalPtr->turnRight();
}

CarnivoreRandomWalking::~CarnivoreRandomWalking() {
	modelPtr->deleteAction(this);
}

void CarnivoreRandomWalking::performAction() {
	// nothing to do
}

Action* CarnivoreRandomWalking::chooseNextAction() {
	auto animalVector = modelPtr->getAnimalsInSight(
			animalPtr->returnCoodtinates(),
			animalPtr->returnLocationData()->sightLen_,
			animalPtr->returnLocationData()->lookingAngle,
			animalPtr->returnLocationData()->lookingRad);

	for (auto animal : animalVector) {
		if (animal->getAttributes().eatNeed_ <= 9.0) {
			if (animal->isHerbivore()) {
				return new Hunting(animalPtr, animal);
			}
		} else
			return new Hunting(animalPtr, animal);
	}

	return this;
}
