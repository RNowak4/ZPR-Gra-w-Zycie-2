/*
 * Follow.cpp
 *
 *  Created on: 22 maj 2015
 *      Author: radek
 */

#include "Follow.h"

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
		auto locationData = animalPtr->returnLocationData();
		auto animalVector = modelPtr->getAnimalsInSight(
				locationData->coordinates_, locationData->sightLen_,
				locationData->lookingAngle, locationData->lookingRad);

		unsigned distance = Model::countDistance(locationData->coordinates_,
				animalToFollowPtr->returnLocationData()->coordinates_);
		for (auto animal : animalVector) {
			if (animal != animalToFollowPtr && animal->isHerbivore()) {
				if (Model::countDistance(locationData->coordinates_,
						animal->returnLocationData()->coordinates_)
						< distance) {
					animalToFollowPtr = animal;
				}
			}
		}

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
