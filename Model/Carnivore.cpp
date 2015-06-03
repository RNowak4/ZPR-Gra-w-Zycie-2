/**
 * @file Carnivore.cpp
 * @brief Implementation of the Carnivore class
 *
 * @author Radoslaw Nowak
 */

#include "Carnivore.h"

#include "Actions/Action.h"
#include "Constants.h"
#include "Parameters.h"

Carnivore::Carnivore(unsigned x, unsigned y) :
		Animal(x, y) {
	locationData_.animalType_ = CARNIVORE;
	locationData_.sightLen_ = actualAttributes_.sightLength_;
	locationData_.lookingRad = actualAttributes_.sightAngle_;
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

	eatNeed_ += actualAttributes_.eatNeed_* Parameters::simulationSpeed;
	sleepNeed_ += actualAttributes_.sleepNeed_* Parameters::simulationSpeed;

	if (actualAttributes_.sleepNeed_ >= Constants::DEFAULT_MAXIMAL_VALUE)
		actualAttributes_.sleepNeed_ = Constants::DEFAULT_MAXIMAL_VALUE;
}
