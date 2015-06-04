/*
 * Copulation.cpp
 *
 *  Created on: 4 cze 2015
 *      Author: radek
 */

#include "Copulation.h"

#include <ctime>

#include "../Animal.h"
#include "../Attributes.h"
#include "../Model.h"
#include "../States/Mother.h"
#include "../ViewStructs.h"
#include "CarnivoreRandomWalking.h"
#include "HerbivoreRandomWalking.h"

Copulation::Copulation(Animal* animalPtr_, Animal* animalToFollow) :
		Action(animalPtr_), animalToFollowPtr(animalToFollow) {
	this->animalPtr->setAcceleration(0.1);
	this->animalPtr->stopTurning();
	this->animalPtr->setLookingAngle(
			Model::countAngle(this->animalPtr->returnCoodtinates(),
					animalToFollowPtr->returnCoodtinates()));
}

Copulation::~Copulation() {
	modelPtr->deleteAction(this);
}

void Copulation::performAction() {
	if (animalToFollowPtr != nullptr) {
		auto lookingAngle = Model::countAngle(animalPtr->returnCoodtinates(),
				animalToFollowPtr->returnCoodtinates());

		animalPtr->setLookingAngle(lookingAngle);
	}
}

Action* Copulation::chooseNextAction() {
	if (animalToFollowPtr != nullptr) {
		auto locationData = animalPtr->returnLocationData();
		auto animalVector = modelPtr->getAnimalsInSight(
				locationData->coordinates_, locationData->sightLen_,
				locationData->lookingAngle, locationData->lookingRad);
		auto animalType = locationData->animalType_;
		Animal* mother;

		unsigned distance = Model::countDistance(locationData->coordinates_,
				animalToFollowPtr->returnLocationData()->coordinates_);

		if (distance <= 5) {
			if (locationData->animalSex_ == FEMALE) {
				mother = animalPtr;
			} else {
				mother = animalToFollowPtr;
			}

			if (animalType == CARNIVORE) {
				modelPtr->createCarnivoreChild(locationData->coordinates_.x,
						locationData->coordinates_.y,
						animalPtr->getAttributes().inheritAttributes(
								animalToFollowPtr->getAttributes()), mother);
				animalToFollowPtr->setAction(
						ActionPtr(
								new CarnivoreRandomWalking(animalToFollowPtr)));
			} else {
				modelPtr->createHerbivoreChild(locationData->coordinates_.x,
						locationData->coordinates_.y,
						animalPtr->getAttributes().inheritAttributes(
								animalToFollowPtr->getAttributes()), mother);
				animalToFollowPtr->setAction(
						ActionPtr(
								new HerbivoreRandomWalking(animalToFollowPtr)));
			}

			mother->addState(StatePtr(new Mother(mother)));

			animalToFollowPtr->returnTimeSiceCopulatio() =
					animalPtr->returnTimeSiceCopulatio() = time(0);
			animalToFollowPtr->returnLocationData()->coordinates_.x += 20;
			animalToFollowPtr->returnLocationData()->coordinates_.y += 20;
			++animalPtr->getChildrenNumber();
			++animalToFollowPtr->getChildrenNumber();
			animalToFollowPtr = nullptr;
		}

	} else {
		if (animalPtr->returnLocationData()->animalType_ == CARNIVORE) {
			return new CarnivoreRandomWalking(animalPtr);
		} else {
			return new HerbivoreRandomWalking(animalPtr);
		}
	}

	return this;
}

void Copulation::deleteAnimal(const Animal* animalPtr) {
	if (this->animalToFollowPtr == animalPtr) {
		animalToFollowPtr = nullptr;
	}
}
