/**
* @file FeedChildren.cpp
* @brief Implementation of the FeedChildren class
*
* @author Radoslaw Nowak
*/


#include "FeedChildren.h"

#include "../Model.h"
#include "CarnivoreRandomWalking.h"

FeedChildren::FeedChildren(Animal* animal_ptr) :
		CarnivoreAction(animal_ptr), currentChild(nullptr) {
	animalPtr->setVelocity(1.0);
	animalPtr->stopTurning();
}

FeedChildren::~FeedChildren() {
	modelPtr->deleteAction(this);
}

void FeedChildren::performAction() {
	if (currentChild != nullptr) {
		this->animalPtr->setLookingAngle(
				Model::countAngle(this->animalPtr->returnCoodtinates(),
						currentChild->returnCoodtinates()));
		if (Model::countDistance(animalPtr->returnCoodtinates(),
				currentChild->returnCoodtinates()) < 40) {
			currentChild->returnEatNeed()-= 4.0;
			animalPtr->returnEatNeed() += 0.3;
			currentChild = nullptr;
		}
	}

	if (currentChild == nullptr) {
		for (auto child : childrenList) {
			if (child->returnEatNeed() > 6.0) {
				currentChild = child;
				break;
			}
		}
	}
}

Action* FeedChildren::chooseNextAction() {
	for (auto child : childrenList) {
		if (child->returnEatNeed() > 6.0) {
			currentChild = child;
			return this;
		}
	}

	return new CarnivoreRandomWalking(animalPtr);
}

void FeedChildren::deleteAnimal(const Animal* ptrToDelete) {
/*	for (auto it = childrenList.begin(); it != childrenList.end(); ++it) {
		if (*it == ptrToDelete) {
			childrenList.erase(it);
			break;
		}
	}*/
}
