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
#include "Hunting.h"

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

	return this;
}
