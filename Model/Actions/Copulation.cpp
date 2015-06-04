/*
 * Copulation.cpp
 *
 *  Created on: 4 cze 2015
 *      Author: radek
 */

#include "Copulation.h"

#include "../Animal.h"
#include "../Model.h"
#include "../ViewStructs.h"
#include "CarnivoreRandomWalking.h"

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
		auto locationData = animalPtr->returnLocationData();
		auto animalVector = modelPtr->getAnimalsInSight(
				locationData->coordinates_, locationData->sightLen_,
				locationData->lookingAngle, locationData->lookingRad);

		unsigned distance = Model::countDistance(locationData->coordinates_,
				animalToFollowPtr->returnLocationData()->coordinates_);

		// zrobic kopulacje - porownac czy plcie sa rozne i te same gatunki i
		// utworzyc new Colupation dla tego obiektu i dla obiektu pozadania.
		// Nalezy tez sprawdzic, czy drugi zwierzak moze miec dzieci
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
	}
}

Action* Copulation::chooseNextAction() {
	if (animalToFollowPtr == nullptr) {
		return new CarnivoreRandomWalking(this->animalPtr);
	}

	return this;
}

void Copulation::deleteAnimal(const Animal* animalPtr) {
	if (this->animalToFollowPtr == animalPtr) {
		animalToFollowPtr = nullptr;
	}
}
