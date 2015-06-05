/**
* @file Chasing.cpp
* @brief Implementation of the Chasing class
*
* @author Radoslaw Nowak
*/

#include "Chasing.h"

#include "../Animal.h"
#include "../Model.h"
#include "../ViewStructs.h"
#include "CarnivoreRandomWalking.h"

Chasing::Chasing(Animal* animal_ptr, Animal* animal_ptr_2) :
		Action(animal_ptr), animalToFollowPtr(animal_ptr_2) {
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
			if (animalToFollowPtr->getAttributes().strength_
					< animalPtr->getAttributes().strength_) {
				modelPtr->killAnimal(animalToFollowPtr);
				animalPtr->returnEatNeed() -= 4.0;
				if (animalPtr->returnEatNeed() < 0.0)
					animalPtr->returnEatNeed() = 0.0;
			} else {
				/*if(animalToFollowPtr->returnLocationData()->animalType_ == CARNIVORE) {
					animalPtr->markToKill();
				}
				else {
					animalToFollowPtr = nullptr;
				}*/
				//TODO wybrac jedna z tych metod
				animalPtr->markToKill();
			}
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
