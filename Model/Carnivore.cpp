/**
 * @file Carnivore.cpp
 * @brief Implementation of the Carnivore class
 *
 * @author Radoslaw Nowak
 */

#include "Carnivore.h"

#include "Actions/Action.h"
#include "Constants.h"

Carnivore::Carnivore(unsigned x, unsigned y) :
		Animal(x, y) {
	locationData_.animalType_ = CARNIVORE;
	locationData_.sightLen_ = Constants::DEFAULT_CARNIVORE_SIGHT_LEN;
	locationData_.lookingRad = Constants::DEFAULT_CARNIVORE_SIGHT_RAD;
}

Carnivore::Carnivore(unsigned x, unsigned y, const Modifiers& modifiers) :
		Animal(x, y, modifiers, CARNIVORE) {
}

void Carnivore::updateStatus() {
	currentAction->performAction();
	Action* chosenAction = currentAction->chooseNextAction();
	if (currentAction.get() != chosenAction) {
		currentAction = shared_ptr < Action > (chosenAction);
	}

	actualAttributes_.eatNeed_ += Constants::DEFAULT_CARNIVORE_CONSUMPTION;
	actualAttributes_.sleepNeed_ += Constants::DEFAULT_CARNIVORE_EXAUSTING;

	if (actualAttributes_.sleepNeed_ >= Constants::DEFAULT_MAXIMAL_VALUE)
		actualAttributes_.sleepNeed_ = Constants::DEFAULT_MAXIMAL_VALUE;
}
