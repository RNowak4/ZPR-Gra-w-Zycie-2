/*
 * TestAction.cpp
 *
 *  Created on: 19 maj 2015
 *      Author: radek
 */

#include "TestAction.h"

#include "../Animal.h"
#include "../Attributes.h"
#include "../Model.h"
#include "../ViewStructs.h"
#include "Eating.h"
#include "Fleeing.h"
#include "Sleeping.h"

TestAction::TestAction(Animal* animalPtr_) :
		Action(animalPtr_) {
	animalPtr->setLookingAngle(0.0);
	animalPtr->setAcceleration(0.0);
	animalPtr->setVelocity(0.5);
	animalPtr->turnRight();
}

TestAction::~TestAction() {
	modelPtr->deleteAction(this);
}

void TestAction::performAction() {
}

Action* TestAction::chooseNextAction() {
	auto animalVector = modelPtr->getAnimalsInSight(
			animalPtr->returnCoodtinates(),
			animalPtr->returnLocationData()->sightLen_/2,
			animalPtr->returnLocationData()->lookingAngle,
			animalPtr->returnLocationData()->lookingRad);

	for(auto animal : animalVector) {
		if(!animal->isHerbivore()) {
			return new Fleeing(animalPtr, animal);
		}
	}

	if (animalPtr->getAttributes().eatNeed_ > 6.0)
		return new Eating(animalPtr);

	if (animalPtr->getAttributes().sleepNeed_ > 8.0)
		return new Sleeping(animalPtr);

	return this;
}
