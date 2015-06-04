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
#include "../ViewStructs.h"
#include "DoNothing.h"
#include "HerbivoreChildEat.h"
#include "HerbivoreChildSleep.h"

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

	if (animalPtr->returnLocationData()->animalType_ == HERBIVORE_CHILD
			&& animalPtr->getAttributes().eatNeed_ > 6.0)
		return new HerbivoreChildEat(animalPtr, motherPtr);

	if (animalPtr->getAttributes().sleepNeed_ > 8.0)
		return new HerbivoreChildSleep(animalPtr, motherPtr);

	return this;
}

void FollowMother::deleteAnimal(const Animal* animalPtr) {
	if (this->motherPtr == animalPtr) {
		motherPtr = nullptr;
	}
}
