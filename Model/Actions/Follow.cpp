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
	this->animalPtr->setVelocity(0.7);
	this->animalPtr->stopTurning();
	this->animalPtr->setLookingAngle(
			defaultModelPtr->countAngle(animalPtr->returnCoodtinates(),
					animalToFollowPtr->returnCoodtinates()));
}

Follow::~Follow() {
}

void Follow::performAction() {
	auto lookingAngle = defaultModelPtr->countAngle(
			animalPtr->returnCoodtinates(),
			animalToFollowPtr->returnCoodtinates());

	animalPtr->setLookingAngle(lookingAngle + 90.0);
}

Action* Follow::chooseNextAction() {
	return this;
}
