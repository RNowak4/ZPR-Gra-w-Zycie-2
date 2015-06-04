/*
 * FollowMother.cpp
 *
 *  Created on: 24 maj 2015
 *      Author: radek
 */

#include "FollowMother.h"

#include "../Animal.h"
#include "../Attributes.h"
#include "../Model.h"
#include "DoNothing.h"

FollowMother::FollowMother(Animal* animalPtr_, Animal* motherPtr_) :
		ChildAction(animalPtr_, motherPtr_) {
	this->animalPtr->setVelocity(
			this->animalPtr->getAttributes().maximalSpeed_ / 2.0);
	this->animalPtr->stopTurning();
	this->animalPtr->setLookingAngle(
			Model::countAngle(this->animalPtr->returnCoodtinates(),
					motherPtr->returnCoodtinates()));
}

FollowMother::~FollowMother() {
	modelPtr->deleteAction(this);
}

void FollowMother::performAction() {
	if (motherPtr != nullptr) {
		auto lookingAngle = Model::countAngle(animalPtr->returnCoodtinates(),
				motherPtr->returnCoodtinates());

		animalPtr->setLookingAngle(lookingAngle);

		if (Model::countDistance(animalPtr->returnCoodtinates(),
				motherPtr->returnCoodtinates()) < 80)
			animalPtr->setVelocity(0.0);
		else
			animalPtr->setVelocity(
					this->animalPtr->getAttributes().maximalSpeed_ / 2.0);
	}
}

Action* FollowMother::chooseNextAction() {
	if (motherPtr == nullptr) {
		return new DoNothing(this->animalPtr);
	}

	return this;
}

void FollowMother::deleteAnimal(const Animal* animalPtr) {
	if (this->motherPtr == animalPtr) {
		motherPtr = nullptr;
	}
}
