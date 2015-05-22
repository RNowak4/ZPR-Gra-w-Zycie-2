/*
 * TestAction.cpp
 *
 *  Created on: 19 maj 2015
 *      Author: radek
 */

#include "TestAction.h"

#include "../Animal.h"


TestAction::TestAction() {
}

TestAction::TestAction(Animal* animalPtr_) :
		Action(animalPtr_) {
	animalPtr->setLookingAngle(20);
	animalPtr->setVelocity(1.0);
	animalPtr->turnRight();
}

TestAction::~TestAction() {
}

void TestAction::performAction() {
	// do nothing
}

Action* TestAction::chooseNextAction() {
	return this;
}
