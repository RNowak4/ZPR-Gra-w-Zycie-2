/**
* @file Copulation.cpp
* @brief Implementation of the Copulation class
*
* @author Radoslaw Nowak
*/

#include "Copulation.h"

#include <ctime>
#include <cstdlib>

#include "../Animal.h"
#include "../Attributes.h"
#include "../Constants.h"
#include "../Model.h"
#include "../Parameters.h"
#include "../States/Childhood.h"
#include "../States/Mother.h"
#include "../ViewStructs.h"
#include "CarnivoreRandomWalking.h"
#include "HerbivoreRandomWalking.h"

Copulation::Copulation(Animal* animal_ptr, Animal* animal_to_follow) :
		Action(animal_ptr), animalToFollowPtr(animal_to_follow) {
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
		Animal* child;
		Animal* mother;

		unsigned distance = Model::countDistance(locationData->coordinates_,
				animalToFollowPtr->returnLocationData()->coordinates_);

		if (distance <= (Constants::DEFAULT_COPULATION_RANGE / Parameters::simulationSpeed)) {
			if (rand() % 100 > 25) {
				animalToFollowPtr->returnTimeSiceCopulation() =
					animalPtr->returnTimeSiceCopulation() = time(0);
				if (animalType == CARNIVORE) {
					animalToFollowPtr->setAction(ActionPtr(new CarnivoreRandomWalking(animalToFollowPtr)));
					return new CarnivoreRandomWalking(animalPtr);
				}
				else {
					animalToFollowPtr->setAction(ActionPtr(new HerbivoreRandomWalking(animalToFollowPtr)));
					return new HerbivoreRandomWalking(animalPtr);
				}
			}

			if (locationData->animalSex_ == FEMALE) {
				mother = animalPtr;
			} else {
				mother = animalToFollowPtr;
			}

			if (animalType == CARNIVORE) {
				child = modelPtr->createCarnivoreChild(
						locationData->coordinates_.x,
						locationData->coordinates_.y,
						animalPtr->getAttributes().inheritAttributes(
								animalToFollowPtr->getAttributes()), mother);
				animalToFollowPtr->setAction(
						ActionPtr(
								new CarnivoreRandomWalking(animalToFollowPtr)));
			} else {
				child = modelPtr->createHerbivoreChild(
						locationData->coordinates_.x,
						locationData->coordinates_.y,
						animalPtr->getAttributes().inheritAttributes(
								animalToFollowPtr->getAttributes()), mother);
				animalToFollowPtr->setAction(
						ActionPtr(
								new HerbivoreRandomWalking(animalToFollowPtr)));
			}

			mother->addState(StatePtr(new Mother(mother)));
			mother->childrenList.push_back(child);
			child->addState(StatePtr(new Childhood(child, mother)));

			animalToFollowPtr->returnTimeSiceCopulation() =
					animalPtr->returnTimeSiceCopulation() = time(0);
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
