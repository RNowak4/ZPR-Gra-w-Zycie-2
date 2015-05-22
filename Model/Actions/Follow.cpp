/*
 * Follow.cpp
 *
 *  Created on: 22 maj 2015
 *      Author: radek
 */

#include "Follow.h"

#include "../Animal.h"
#include "../Model.h"

Follow::Follow(Animal* animalPtr_, Animal* animalPtr) :
		Action(animalPtr_), animalToFollowPtr(animalPtr) {
	this->animalPtr->setVelocity(1.0);
	this->animalPtr->stopTurning();
	this->animalPtr->setLookingAngle(
			defaultModelPtr->countAngle(animalPtr->returnCoodtinates(),
					animalToFollowPtr->returnCoodtinates()));
}

Follow::~Follow() {
}

void Follow::performAction() {
	animalPtr->setLookingAngle(
			defaultModelPtr->countAngle(animalPtr->returnCoodtinates(),
					animalToFollowPtr->returnCoodtinates()));
}

Action* Follow::chooseNextAction() {
	return this;
}
