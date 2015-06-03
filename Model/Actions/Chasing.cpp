/*
 * Chasing.cpp
 *
 *  Created on: 3 cze 2015
 *      Author: radek
 */

#include "Chasing.h"

#include "../Animal.h"
#include "../Model.h"
#include "../ViewStructs.h"
#include "CarnivoreRandomWalking.h"


Chasing::Chasing(Animal* animalPtr_, Animal* animalPtr) :
		Action(animalPtr_), animalToFollowPtr(animalPtr) {
	this->animalPtr->setAcceleration(0.1);
	this->animalPtr->stopTurning();
	this->animalPtr->setLookingAngle(
			Model::countAngle(this->animalPtr->returnCoodtinates(),
					animalToFollowPtr->returnCoodtinates()));
}

Chasing::~Chasing() {
	modelPtr->deleteAction(this);
}

void Chasing::performAction() {
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
			animalPtr->returnEatNeed() -= 4.0;
			if (animalPtr->returnEatNeed() < 0.0)
				animalPtr->returnEatNeed() = 0.0;
		}
	}
}

Action* Chasing::chooseNextAction() {
	if (animalToFollowPtr == nullptr) {
		return new CarnivoreRandomWalking(this->animalPtr);
	}

	return this;
}

void Chasing::deleteAnimal(const Animal* animalPtr) {
	if (this->animalToFollowPtr == animalPtr) {
		animalToFollowPtr = nullptr;
	}
}
