/*
 * LookingForPartner.cpp
 *
 *  Created on: 4 cze 2015
 *      Author: radek
 */

#include "LookingForPartner.h"

#include "../Animal.h"
#include "../Constants.h"
#include "../Model.h"

LookingForPartner::LookingForPartner(Animal* animalPtr_) :
		RandomWalking(animalPtr_) {
}

LookingForPartner::~LookingForPartner() {
	modelPtr->deleteAction(this);
}

Action* LookingForPartner::chooseNextAction() {
	if (animalPtr->returnEatNeed() >= Constants::DEFAULT_CARNIVORE_HUNGER) {
		// TODO kopulacja
		//return new Hunting(animalPtr);
	}

	return this;
}
