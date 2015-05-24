/*
 * FeedChildren.cpp
 *
 *  Created on: 24 maj 2015
 *      Author: radek
 */

#include "FeedChildren.h"

#include "../Attributes.h"
#include "../Model.h"
#include "TestAction.h"

FeedChildren::FeedChildren(Animal* animalPtr_) :
		Action(animalPtr_), currentChild(nullptr) {
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
			currentChild->getAttributes().eatNeed_ -= 4.0;
			animalPtr->getAttributes().eatNeed_ += 0.3;
			currentChild = nullptr;
		}
	}

	if (currentChild == nullptr) {
		for (auto child : childrenList) {
			if (child->getAttributes().eatNeed_ > 6.0) {
				currentChild = child;
				break;
			}
		}
	}
}

Action* FeedChildren::chooseNextAction() {
	for (auto child : childrenList) {
		if (child->getAttributes().eatNeed_ > 6.0) {
			currentChild = child;
			return this;
		}
	}

	return new TestAction(animalPtr);
}

void FeedChildren::deleteAnimal(const Animal* ptrToDelete) {
	for (auto it = childrenList.begin(); it != childrenList.end(); ++it) {
		if (*it == ptrToDelete) {
			childrenList.erase(it);
			break;
		}
	}
}
