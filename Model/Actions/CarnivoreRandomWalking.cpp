/*
 * CarnivoreRandomWalking.cpp
 *
 *  Created on: 27 maj 2015
 *      Author: radek
 */

#include "CarnivoreRandomWalking.h"

#include "../Animal.h"
#include "../Constants.h"
#include "../Model.h"
#include "CarnivoreSleeping.h"
#include "FeedChildren.h"
#include "Hunting.h"
#include "LookingForPartner.h"

CarnivoreRandomWalking::CarnivoreRandomWalking(Animal* animalPtr_) :
		RandomWalking(animalPtr_) {
}

CarnivoreRandomWalking::~CarnivoreRandomWalking() {
	modelPtr->deleteAction(this);
}

Action* CarnivoreRandomWalking::chooseNextAction() {
	if (animalPtr->returnEatNeed() >= Constants::DEFAULT_CARNIVORE_HUNGER) {
		return new Hunting(animalPtr);
	}

	for(auto child : animalPtr->childrenList) {
		if(child->returnEatNeed() > 7.5) {
			return new FeedChildren(animalPtr);
		}
	}

	if (animalPtr->returnSleepNeed() > 8)
		return new CarnivoreSleeping(animalPtr);

	if (animalPtr->canHaveChild()) {
		return new LookingForPartner(animalPtr);
	}

	return this;
}
