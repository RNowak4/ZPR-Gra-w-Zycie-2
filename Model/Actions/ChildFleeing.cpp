/*
 * ChildFleeing.cpp
 *
 *  Created on: 4 cze 2015
 *      Author: radek
 */

#include "ChildFleeing.h"

#include "../Animal.h"
#include "../Model.h"
#include "../ViewStructs.h"
#include "FollowMother.h"

ChildFleeing::ChildFleeing(Animal* animal_ptr, Animal* mother_ptr,
		Animal* hunter_) :
		ChildAction(animal_ptr, mother_ptr), hunter(hunter_) {
	animalPtr->setAcceleration(0.05);
	this->animalPtr->setLookingAngle(
			Model::countAngle(this->animalPtr->returnCoodtinates(),
					hunter->returnCoodtinates()) + 180);
	this->animalPtr->stopTurning();

}

ChildFleeing::~ChildFleeing() {
	modelPtr->deleteAction(this);
}

void ChildFleeing::performAction() {
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

Action* ChildFleeing::chooseNextAction() {
	if (hunter == nullptr)
		return new FollowMother(animalPtr, motherPtr);

	return this;
}

void ChildFleeing::deleteAnimal(const Animal* toDelete) {
	if (hunter == toDelete)
		hunter = nullptr;
}
