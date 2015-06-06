/**
* @file FollowMother.cpp
* @brief Implementation of the FollowMother class
*
* @author Radoslaw Nowak
*/


#include "FollowMother.h"

#include "../Animal.h"
#include "../Attributes.h"
#include "../Model.h"
#include "../ViewStructs.h"
#include "DoNothing.h"
#include "HerbivoreChildEat.h"
#include "HerbivoreChildSleep.h"

FollowMother::FollowMother(Animal* animal_ptr, Animal* mother_ptr) :
		ChildAction(animal_ptr, mother_ptr) {
	this->animalPtr->setVelocity(
			this->animalPtr->getAttributes().maximalSpeed_ / 2.0);
	this->animalPtr->stopTurning();
	this->animalPtr->setLookingAngle(
			Model::countAngle(this->animalPtr->returnCoodtinates(),
					motherPtr->returnCoodtinates()));
}

FollowMother::~FollowMother() {
	modelPtr->deleteAction(this);
}

void FollowMother::performAction() {
	if (motherPtr != nullptr) {
		auto lookingAngle = Model::countAngle(animalPtr->returnCoodtinates(),
				motherPtr->returnCoodtinates());

		animalPtr->setLookingAngle(lookingAngle);

		if (Model::countDistance(animalPtr->returnCoodtinates(),
				motherPtr->returnCoodtinates()) < MIN_DIST)
			animalPtr->setVelocity(0.0);
		else if (Model::countDistance(animalPtr->returnCoodtinates(),
				motherPtr->returnCoodtinates()) > MAX_DIST)
			animalPtr->setVelocity(
					this->animalPtr->getAttributes().maximalSpeed_ / 2.0);
	}
}

Action* FollowMother::chooseNextAction() {
	if (motherPtr == nullptr) {
		return new DoNothing(this->animalPtr, motherPtr);
	}

	if (animalPtr->returnLocationData()->animalType_ == HERBIVORE_CHILD
			&& animalPtr->returnEatNeed() > 6.0)
		return new HerbivoreChildEat(animalPtr, motherPtr);

	if (animalPtr->returnSleepNeed() > 8.0)
		return new HerbivoreChildSleep(animalPtr, motherPtr);

	return this;
}

void FollowMother::deleteAnimal(const Animal* animalPtr) {
	if (this->motherPtr == animalPtr) {
		motherPtr = nullptr;
	}
}
