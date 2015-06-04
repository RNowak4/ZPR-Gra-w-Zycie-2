/*
 * Fleeing.cpp
 *
 *  Created on: 24 maj 2015
 *      Author: radek
 */

#include "Fleeing.h"

#include "../Animal.h"
#include "../Model.h"
#include "../ViewStructs.h"
#include "HerbivoreRandomWalking.h"

Fleeing::Fleeing(Animal* animalPtr_, Animal* hunter_) :
		Action(animalPtr_), hunter(hunter_) {
	animalPtr->setAcceleration(0.05);
	this->animalPtr->setLookingAngle(
			Model::countAngle(this->animalPtr->returnCoodtinates(),
					hunter->returnCoodtinates()) + 180);
	this->animalPtr->stopTurning();
}

Fleeing::~Fleeing() {
	modelPtr->deleteAction(this);
}

void Fleeing::performAction() {
	if (hunter != nullptr) {
		this->animalPtr->setLookingAngle(
				Model::countAngle(this->animalPtr->returnCoodtinates(),
						hunter->returnCoodtinates()) + 180);

		if (Model::countDistance(this->animalPtr->returnCoodtinates(),
				hunter->returnCoodtinates())
				> this->animalPtr->returnLocationData()->sightLen_) {
			hunter = nullptr;
		}
	}
}

Action* Fleeing::chooseNextAction() {
	if (hunter == nullptr)
		return new HerbivoreRandomWalking(animalPtr);

	return this;
}

void Fleeing::deleteAnimal(const Animal* toDelete) {
	if (hunter == toDelete)
		hunter = nullptr;
}
