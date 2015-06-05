/**
* @file HerbivoreChildEat.cpp
* @brief Implementation of the HerbivoreChildEat class
*
* @author Radoslaw Nowak
*/


#include "HerbivoreChildEat.h"

#include "../Animal.h"
#include "../Attributes.h"
#include "../Constants.h"
#include "../Model.h"
#include "../ViewStructs.h"
#include "Fleeing.h"
#include "FollowMother.h"

HerbivoreChildEat::HerbivoreChildEat(Animal* animal_ptr, Animal* mother_ptr) :
		ChildAction(animal_ptr, mother_ptr) {
	animalPtr->setVelocity(0.0);
	animalPtr->setAcceleration(0.0);
	animalPtr->stopTurning();
	animalPtr->returnLocationData()->sightLen_ /=
			Constants::DEFAULT_HERBIVORE_EATING_SIGHT_REDUCTION;
}

HerbivoreChildEat::~HerbivoreChildEat() {
	animalPtr->returnLocationData()->sightLen_ *=
			Constants::DEFAULT_HERBIVORE_EATING_SIGHT_REDUCTION;
	modelPtr->deleteAction(this);
}

void HerbivoreChildEat::performAction() {
	animalPtr->returnEatNeed() -= 0.2;
}

Action* HerbivoreChildEat::chooseNextAction() {
	auto animalsVector = modelPtr->getNearlyAnimals(
			animalPtr->returnLocationData()->coordinates_,
			animalPtr->getAttributes().hearingRange_);

	for (auto animal : animalsVector) {
		if (animalPtr->isDangerous(animal)) {
			return new Fleeing(animalPtr, animal);
		}
	}

	if (animalPtr->returnEatNeed() < 2.5) {
		return new FollowMother(animalPtr, motherPtr);
	}

	return this;
}

void HerbivoreChildEat::deleteAnimal(const Animal*) {
	// nothing to do about that
}
