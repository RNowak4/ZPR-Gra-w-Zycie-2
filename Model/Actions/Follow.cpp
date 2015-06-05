/**
* @file Follow.cpp
* @brief Implementation of the Follow class
*
* @author Radoslaw Nowak
*/

#include "Follow.h"

#include "../Animal.h"
#include "../Attributes.h"
#include "../Model.h"
#include "../ViewStructs.h"
#include "HerbivoreRandomWalking.h"

using namespace std;

Follow::Follow(Animal* animal_ptr, Animal* animal_ptr_2) :
		Action(animal_ptr), animalToFollowPtr(animal_ptr_2) {
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
			animalPtr->returnEatNeed() -= 4.0;
			if (animalPtr->returnEatNeed() < 0.0)
				animalPtr->returnEatNeed() = 0.0;
		}
	}
}

Action* Follow::chooseNextAction() {
	if (animalToFollowPtr == nullptr) {
		return new HerbivoreRandomWalking(this->animalPtr);
	}

	return this;
}

void Follow::deleteAnimal(const Animal* animalPtr) {
	if (this->animalToFollowPtr == animalPtr) {
		animalToFollowPtr = nullptr;
	}
}
