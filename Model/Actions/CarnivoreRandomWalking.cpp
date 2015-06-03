/*
 * CarnivoreRandomWalking.cpp
 *
 *  Created on: 27 maj 2015
 *      Author: radek
 */

#include "CarnivoreRandomWalking.h"

#include <ctime>

#include "../Animal.h"
#include "../Constants.h"
#include "../Model.h"
#include "../ViewStructs.h"
#include "Hunting.h"

CarnivoreRandomWalking::CarnivoreRandomWalking(Animal* animalPtr_) :
		CarnivoreAction(animalPtr_) {
	animalPtr->setLookingAngle(0);
	animalPtr->setVelocity(0.7);
	animalPtr->setAcceleration(0.0);
	animalPtr->turnRight();
	lastChangeTime = time(0);
	distribution1 = std::uniform_int_distribution<int>(0, 2);
	distribution2 = std::uniform_int_distribution<int>(0, 1);
}

CarnivoreRandomWalking::~CarnivoreRandomWalking() {
	modelPtr->deleteAction(this);
}

void CarnivoreRandomWalking::performAction() {
	if (time(0) - lastChangeTime > Constants::DEFAULT_ACTION_TIME_CHANGE) {
		switch (distribution2(generator)) {
		case 0:
			animalPtr->setVelocity(0.7);
			switch (distribution1(generator)) {
			case 0:
				animalPtr->turnLeft();
				break;

			case 1:
				animalPtr->stopTurning();
				break;

			case 2:
				animalPtr->turnRight();
				break;

			default:
				break;
			}
			break;

		case 1:
			animalPtr->setVelocity(0.0);
			animalPtr->stopTurning();
			break;
		}

		lastChangeTime = time(0);
	}
}

Action* CarnivoreRandomWalking::chooseNextAction() {
	auto animalVector = modelPtr->getAnimalsInSight(
			animalPtr->returnCoodtinates(),
			animalPtr->returnLocationData()->sightLen_,
			animalPtr->returnLocationData()->lookingAngle,
			animalPtr->returnLocationData()->lookingRad);

	if (animalPtr->returnEatNeed() >= Constants::DEFAULT_CARNIVORE_HUNGER) {
		for (auto animal : animalVector) {
			if (animal->isHerbivore()) {
				return new Hunting(animalPtr, animal);
			}
		}
	}

	return this;
}
