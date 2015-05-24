/*
 * FollowMother.cpp
 *
 *  Created on: 24 maj 2015
 *      Author: radek
 */

#include "FollowMother.h"

#include "../Model.h"
#include "Follow.h"
#include "RandomWalking.h"

FollowMother::FollowMother(Animal* animalPtr_, Animal* animalPtr) :
		Action(animalPtr_), animalToFollowPtr(animalPtr) {
	this->animalPtr->setVelocity(0.7);
	this->animalPtr->stopTurning();
	this->animalPtr->setLookingAngle(
			Model::countAngle(this->animalPtr->returnCoodtinates(),
					animalToFollowPtr->returnCoodtinates()));
}

FollowMother::~FollowMother() {
	modelPtr->deleteAction(this);
}

void FollowMother::performAction() {
	if (animalToFollowPtr != nullptr) {
		auto lookingAngle = Model::countAngle(animalPtr->returnCoodtinates(),
				animalToFollowPtr->returnCoodtinates());

		animalPtr->setLookingAngle(lookingAngle);

		if (Model::countDistance(animalPtr->returnCoodtinates(),
				animalToFollowPtr->returnCoodtinates()) < 80)
			animalPtr->setVelocity(0.0);
		else
			animalPtr->setVelocity(0.7);
	}
}

Action* FollowMother::chooseNextAction() {
	if (animalToFollowPtr == nullptr) {
		return new RandomWalking(this->animalPtr);
	}

	return this;
}

void FollowMother::deleteAnimal(const Animal* animalPtr) {
	if (this->animalToFollowPtr == animalPtr) {
		animalToFollowPtr = nullptr;
	}
}
