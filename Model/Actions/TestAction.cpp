/*
 * TestAction.cpp
 *
 *  Created on: 19 maj 2015
 *      Author: radek
 */

#include "TestAction.h"

#include "../Animal.h"
#include "../Attributes.h"
#include "../Constants.h"
#include "../Model.h"
#include "../ViewStructs.h"
#include "Eating.h"
#include "Fleeing.h"
#include "Sleeping.h"

TestAction::TestAction(Animal* animalPtr_) :
		Action(animalPtr_) {
	animalPtr->setAcceleration(0.0);
	animalPtr->setVelocity(0.5);
	animalPtr->turnRight();
	lastChangeTime = time(0);
	distribution1 = std::uniform_int_distribution<int>(0, 2);
	distribution2 = std::uniform_int_distribution<int>(0, 4);
}

TestAction::~TestAction() {
	modelPtr->deleteAction(this);
}

void TestAction::performAction() {
	/*if (time(0) - lastChangeTime > Constants::DEFAULT_ACTION_TIME_CHANGE) {
		switch (distribution2(generator)) {
		case 4:
			animalPtr->setVelocity(0.0);
			animalPtr->stopTurning();
			break;

		default:
			animalPtr->setVelocity(0.7);
			switch (distribution1(generator)) {
			case 0:
				animalPtr->turnRight();
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
		}

		lastChangeTime = time(0);
	}*/

	animalPtr->turnLeft();
}

Action* TestAction::chooseNextAction() {
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

	if (animalPtr->getAttributes().eatNeed_ > 6.0)
		return new Eating(animalPtr);

	if (animalPtr->getAttributes().sleepNeed_ > 8.0)
		return new Sleeping(animalPtr);

	return this;
}
