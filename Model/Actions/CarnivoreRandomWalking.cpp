/*
 * CarnivoreRandomWalking.cpp
 *
 *  Created on: 27 maj 2015
 *      Author: radek
 */

#include "CarnivoreRandomWalking.h"

#include "../Animal.h"
#include "../Attributes.h"
#include "../Constants.h"
#include "../Model.h"
#include "CarnivoreSleeping.h"
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

	if (animalPtr->getAttributes().sleepNeed_
			> Constants::DEFAULT_CARNIVORE_EXAUSTING)
		return new CarnivoreSleeping(animalPtr);

	if (animalPtr->canHaveChild()) {
		return new LookingForPartner(animalPtr);
	}

	return this;
}
