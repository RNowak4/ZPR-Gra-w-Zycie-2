/*
 * HerbivoreRandomWalking.cpp
 *
 *  Created on: 4 cze 2015
 *      Author: radek
 */

#include "HerbivoreRandomWalking.h"

#include "../Animal.h"
#include "../Attributes.h"
#include "../Model.h"
#include "../ViewStructs.h"
#include "Eating.h"
#include "Fleeing.h"
#include "LookingForPartner.h"
#include "Sleeping.h"
#include <iostream>
HerbivoreRandomWalking::HerbivoreRandomWalking(Animal* animalPtr_) :
		RandomWalking(animalPtr_) {
}

HerbivoreRandomWalking::~HerbivoreRandomWalking() {
	modelPtr->deleteAction(this);
}

Action* HerbivoreRandomWalking::chooseNextAction() {
	auto animalVector = modelPtr->getAnimalsInSight(
			animalPtr->returnCoodtinates(),
			animalPtr->returnLocationData()->sightLen_ / 2,
			animalPtr->returnLocationData()->lookingAngle,
			animalPtr->returnLocationData()->lookingRad);

	for (auto animal : animalVector) {
		if (!animal->isHerbivore()) {
			return new Fleeing(animalPtr, animal);
		}
	}

	std::cout << animalPtr->getAttributes().eatNeed_ << std::endl;
	if (animalPtr->getAttributes().eatNeed_ > 6.0)
		return new Eating(animalPtr);

	if (animalPtr->getAttributes().sleepNeed_ > 8.0)
		return new Sleeping(animalPtr);

	if (animalPtr->canHaveChild()) {
		return new LookingForPartner(animalPtr);
	}

	return this;
}
