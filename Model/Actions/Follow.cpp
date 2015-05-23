/*
 * Follow.cpp
 *
 *  Created on: 22 maj 2015
 *      Author: radek
 */

#include "Follow.h"

#include <iostream>

#include "../Animal.h"
#include "../Model.h"

Follow::Follow(Animal* animalPtr_, Animal* animalPtr) :
		Action(animalPtr_), animalToFollowPtr(animalPtr) {
	this->animalPtr->setVelocity(0.5);
	this->animalPtr->stopTurning();
	this->animalPtr->setLookingAngle(
			Model::countAngle(this->animalPtr->returnCoodtinates(),
					animalToFollowPtr->returnCoodtinates()));
}

Follow::~Follow() {
}

void Follow::performAction() {
	auto lookingAngle = Model::countAngle(
			animalPtr->returnCoodtinates(),
			animalToFollowPtr->returnCoodtinates());

	animalPtr->setLookingAngle(lookingAngle);
}

Action* Follow::chooseNextAction() {
	return this;
}
