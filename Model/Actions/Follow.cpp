/*
 * Follow.cpp
 *
 *  Created on: 22 maj 2015
 *      Author: radek
 */

#include "Follow.h"

#include <cmath>

#include "../Animal.h"
#include "../Attributes.h"
#include "../Model.h"
#include "RandomWalking.h"

using namespace std;

Follow::Follow(Animal* animalPtr_, Animal* animalPtr) :
		Action(animalPtr_), animalToFollowPtr(animalPtr) {
	this->animalPtr->setVelocity(2.0);
	this->animalPtr->setAcceleration(0.1);
	this->animalPtr->stopTurning();
	this->animalPtr->setLookingAngle(
			Model::countAngle(this->animalPtr->returnCoodtinates(),
					animalToFollowPtr->returnCoodtinates()));
}

Follow::~Follow() {
	modelPtr->deleteAction(this);
}

void Follow::performAction() {
	if (animalToFollowPtr != nullptr) {
		auto lookingAngle = Model::countAngle(animalPtr->returnCoodtinates(),
				animalToFollowPtr->returnCoodtinates());

		animalPtr->setLookingAngle(lookingAngle);

		if (Model::countDistance(animalPtr->returnCoodtinates(),
				animalToFollowPtr->returnCoodtinates()) < 40) {
			modelPtr->killAnimal(animalToFollowPtr);
			animalPtr->getAttributes().eatNeed_ -= 4.0;
			if (animalPtr->getAttributes().eatNeed_ < 0.0)
				animalPtr->getAttributes().eatNeed_ = 0.0;
		}
	}
}

Action* Follow::chooseNextAction() {
	if (animalToFollowPtr == nullptr) {
		return new RandomWalking(this->animalPtr);
	}

	return this;
}

void Follow::deleteAnimal(const Animal* animalPtr) {
	if (this->animalToFollowPtr == animalPtr) {
		animalToFollowPtr = nullptr;
	}
}
