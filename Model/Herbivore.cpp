/**
 * @file Herbivore.cpp
 * @brief Implementation of the Herbivore class
 *
 * @author Radoslaw Nowak
 */

#include "Herbivore.h"

#include "Actions/Action.h"
#include "Constants.h"
#include "Parameters.h"

Herbivore::Herbivore(unsigned x, unsigned y) :
		Animal(x, y) {
	locationData_.animalType_ = HERBIVORE;
	locationData_.sightLen_ = actualAttributes_.sightLength_;
	locationData_.lookingRad = actualAttributes_.sightAngle_;
	actualAttributes_.maximalSpeed_ -= 1.5;
	actualAttributes_.strength_ -= 2.0;
}

Herbivore::Herbivore(unsigned x, unsigned y, const Attributes& attributes) :
		Animal(x, y, attributes) {
	locationData_.animalType_ = HERBIVORE_CHILD;
	locationData_.sightLen_ = actualAttributes_.sightLength_;
	locationData_.lookingRad = actualAttributes_.sightAngle_;
}

void Herbivore::updateStatus() {
	currentAction->performAction();
	Action* chosenAction = currentAction->chooseNextAction();
	if (currentAction.get() != chosenAction) {
		currentAction = shared_ptr < Action > (chosenAction);
	}

	eatNeed_ += actualAttributes_.eatNeed_ * Parameters::simulationSpeed;
	sleepNeed_ += actualAttributes_.sleepNeed_ * Parameters::simulationSpeed;

	if (sleepNeed_ >= Constants::DEFAULT_MAXIMAL_VALUE)
		sleepNeed_ = Constants::DEFAULT_MAXIMAL_VALUE;
}
