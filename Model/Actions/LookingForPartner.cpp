/*
 * LookingForPartner.cpp
 *
 *  Created on: 4 cze 2015
 *      Author: radek
 */

#include "LookingForPartner.h"

#include <vector>

#include "../Animal.h"
#include "../Attributes.h"
#include "../Model.h"
#include "../ViewStructs.h"
#include "CarnivoreSleeping.h"
#include "Copulation.h"
#include "Eating.h"
#include "Fleeing.h"
#include "Hunting.h"
#include "Sleeping.h"

LookingForPartner::LookingForPartner(Animal* animalPtr_) :
		RandomWalking(animalPtr_) {
}

LookingForPartner::~LookingForPartner() {
	modelPtr->deleteAction(this);
}

Action* LookingForPartner::chooseNextAction() {
	auto animalVector = modelPtr->getAnimalsInSight(
			animalPtr->returnCoodtinates(),
			animalPtr->returnLocationData()->sightLen_ / 2,
			animalPtr->returnLocationData()->lookingAngle,
			animalPtr->returnLocationData()->lookingRad);

	if (animalPtr->returnLocationData()->animalType_ == HERBIVORE) {
		for (auto animal : animalVector) {
			if (!animal->isHerbivore()) {
				return new Fleeing(animalPtr, animal);
			}
		}

		if (animalPtr->getAttributes().eatNeed_ > 6.0)
			return new Eating(animalPtr);

		if (animalPtr->getAttributes().sleepNeed_ > 8.0)
			return new Sleeping(animalPtr);
	} else {
		if (animalPtr->getAttributes().eatNeed_ > 6.0)
			return new Hunting(animalPtr);

		if (animalPtr->getAttributes().sleepNeed_ > 8.0)
			return new CarnivoreSleeping(animalPtr);
	}

	animalVector = modelPtr->getAnimalsInSight(animalPtr->returnCoodtinates(),
			animalPtr->returnLocationData()->sightLen_,
			animalPtr->returnLocationData()->lookingAngle,
			animalPtr->returnLocationData()->lookingRad);

	for (auto animal : animalVector) {
		if (animal->returnLocationData()->animalSex_
				!= animalPtr->returnLocationData()->animalSex_
				&& animal->returnLocationData()->animalType_
						== animalPtr->returnLocationData()->animalType_) {
			if (animal->canHaveChild()) {
				animal->setAction(ActionPtr(new Copulation(animal, animalPtr)));
				return new Copulation(animalPtr, animal);
			}
		}
	}

	return this;
}
