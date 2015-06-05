/**
* @file RandomWalking.cpp
* @brief Implementation of the RadnomWalking class
*
* @author Radoslaw Nowak
*/


#include "RandomWalking.h"

#include <cstdlib>

#include "../Animal.h"
#include "../Constants.h"
#include "../Model.h"
#include "../ViewStructs.h"
#include "Eating.h"
#include "Fleeing.h"
#include "Sleeping.h"

RandomWalking::RandomWalking(Animal* animal_ptr) :
		Action(animal_ptr) {
	animalPtr->setLookingAngle(0);
	animalPtr->setVelocity(animalPtr->getAttributes().maximalSpeed_ / 4);
	animalPtr->setAcceleration(0.0);
	animalPtr->turnRight();
	lastChangeTime = time(0);
}

RandomWalking::~RandomWalking() {
	modelPtr->deleteAction(this);
}

void RandomWalking::performAction() {
	if (time(0) - lastChangeTime > Constants::DEFAULT_ACTION_TIME_CHANGE) {
		switch (rand() % 2) {
		case 0:
			animalPtr->setVelocity(0.7);
			switch (rand() % 3) {
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

Action* RandomWalking::chooseNextAction() {
	auto animalVector = modelPtr->getAnimalsInSight(
			animalPtr->returnCoodtinates(),
			animalPtr->returnLocationData()->sightLen_ / 2,
			animalPtr->returnLocationData()->lookingAngle,
			animalPtr->returnLocationData()->lookingRad);

	for (auto animal : animalVector) {
		if (!animal->isHerbivore()) {
			return new Fleeing(animalPtr, animal);
		}
	}

	if (animalPtr->returnEatNeed() > 6.0)
		return new Eating(animalPtr);

	if (animalPtr->returnSleepNeed() > 8.0)
		return new Sleeping(animalPtr);

	return this;
}

void RandomWalking::deleteAnimal(const Animal*) {
	//do nothing
}
