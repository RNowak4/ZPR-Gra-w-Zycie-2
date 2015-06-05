/**
* @file Hunting.cpp
* @brief Implementation of the Hunting class
*
* @author Radoslaw Nowak
*/


#include "Hunting.h"

#include "../Animal.h"
#include "../Attributes.h"
#include "../Constants.h"
#include "../Model.h"
#include "../ViewStructs.h"
#include "Chasing.h"

Hunting::Hunting(Animal* animal_ptr) :
		Action(animal_ptr) {
	animalPtr->setLookingAngle(0);
	animalPtr->setVelocity(
			this->animalPtr->getAttributes().maximalSpeed_ * 0.75);
	animalPtr->setAcceleration(0.0);
	animalPtr->turnRight();
	lastChangeTime = time(0);
	distribution1 = std::uniform_int_distribution<int>(0, 2);
	distribution2 = std::uniform_int_distribution<int>(0, 1);
}

Hunting::~Hunting() {
	modelPtr->deleteAction(this);
}

void Hunting::performAction() {
	if (time(0) - lastChangeTime > Constants::DEFAULT_ACTION_TIME_CHANGE) {
		switch (distribution1(generator)) {
		case 0:
			animalPtr->turnLeft();
			break;

		case 1:
			animalPtr->stopTurning();
			break;

		case 2:
			animalPtr->turnRight();
			break;

		default:
			break;
		}

		lastChangeTime = time(0);
	}
}

Action* Hunting::chooseNextAction() {
	auto animalVector = modelPtr->getAnimalsInSight(
			animalPtr->returnCoodtinates(),
			animalPtr->returnLocationData()->sightLen_,
			animalPtr->returnLocationData()->lookingAngle,
			animalPtr->returnLocationData()->lookingRad);

	for (auto animal : animalVector) {
		if (animal->isHerbivore()) {
			return new Chasing(animalPtr, animal);
		}

		// then attacks everyone
		if (animalPtr->returnEatNeed() > 9.0) {
			return new Chasing(animalPtr, animal);
		}
	}

	return this;
}

void Hunting::deleteAnimal(const Animal* animalPtr) {
}
