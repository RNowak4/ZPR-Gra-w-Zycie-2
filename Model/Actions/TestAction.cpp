/*
 * TestAction.cpp
 *
 *  Created on: 19 maj 2015
 *      Author: radek
 */

#include "TestAction.h"

#include "../Animal.h"
#include "../Model.h"

TestAction::TestAction(Animal* animalPtr_) :
		Action(animalPtr_) {
	animalPtr->setLookingAngle(90);
	animalPtr->setVelocity(1.0);
	animalPtr->turnRight();
}

TestAction::~TestAction() {
	modelPtr->deleteAction(this);
}

void TestAction::performAction() {
}

Action* TestAction::chooseNextAction() {
	return this;
}
