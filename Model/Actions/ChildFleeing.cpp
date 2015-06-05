/**
* @file ChildFleeing.cpp
* @brief Implementation of the ChildFleeing class
*
* @author Radoslaw Nowak
*/


#include "ChildFleeing.h"

#include "../Animal.h"
#include "../Model.h"
#include "../ViewStructs.h"
#include "DoNothing.h"
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

	if(modelPtr == nullptr)
		return new DoNothing(animalPtr, motherPtr);

	return this;
}

void ChildFleeing::deleteAnimal(const Animal* toDelete) {
	if (hunter == toDelete)
		hunter = nullptr;

	if(motherPtr == toDelete)
		motherPtr = nullptr;
}
