/**
 * @file Herbivore.cpp
 * @brief Implementation of the Herbivore class
 *
 * @author Radoslaw Nowak
 */

#include "Herbivore.h"

#include "Actions/Action.h"
#include "Constants.h"

Herbivore::Herbivore(unsigned x, unsigned y) :
		Animal(x, y) {
	locationData_.animalType_ = HERBIVORE;
	locationData_.sightLen_ = Constants::DEFAULT_HERBIVORE_SIGHT_LEN;
	locationData_.lookingRad = Constants::DEFAULT_HERBIVORE_SIGHT_RAD;
}

Herbivore::Herbivore(unsigned x, unsigned y, const Modifiers& modifiers) :
		Animal(x, y, modifiers, CARNIVORE) {
}

void Herbivore::updateStatus() {
	currentAction->performAction();
	Action* chosenAction = currentAction->chooseNextAction();
	if (currentAction.get() != chosenAction) {
		currentAction = shared_ptr < Action > (chosenAction);
	}

	actualAttributes_.eatNeed_ += Constants::DEFAULT_HERBIVORE_CONSUMPTION;
	actualAttributes_.sleepNeed_ += Constants::DEFAULT_HERBIVORE_EXAUSTING;

	if (actualAttributes_.sleepNeed_ >= Constants::DEFAULT_MAXIMAL_VALUE)
		actualAttributes_.sleepNeed_ = Constants::DEFAULT_MAXIMAL_VALUE;
}
