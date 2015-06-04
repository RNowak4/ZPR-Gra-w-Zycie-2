/*
 * DoNothing.cpp
 *
 *  Created on: 4 cze 2015
 *      Author: radek
 */

#include "DoNothing.h"

#include "../Animal.h"
#include "../Model.h"

DoNothing::DoNothing(Animal* animalPtr_) :
		Action(animalPtr_) {
	animalPtr->setVelocity(0.0);
	animalPtr->setAcceleration(0.0);
	animalPtr->stopTurning();
}

DoNothing::~DoNothing() {
	modelPtr->deleteAction(this);
}

void DoNothing::performAction() {
	//do nothing
}

Action* DoNothing::chooseNextAction() {
	return this;
}

void DoNothing::deleteAnimal(const Animal*) {
	//do nothing
}
