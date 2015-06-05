/**
 * @file Herbivore.cpp
 * @brief Implementation of the Herbivore class
 *
 * @author Radoslaw Nowak
 */

#include "Herbivore.h"

#include <cmath>
#include <cstdlib>
#include <ctime>

#include "Actions/HerbivoreRandomWalking.h"
#include "Constants.h"
#include "Parameters.h"
#include "States/Childhood.h"
#include "States/Illness.h"

Herbivore::Herbivore(unsigned x, unsigned y) :
		Animal(x, y) {
	locationData.animalType_ = HERBIVORE;
	locationData.sightLen_ = actualAttributes.sightLength_;
	locationData.lookingRad = actualAttributes.sightAngle_;
	actualAttributes.maximalSpeed_ -= 1.5;
	actualAttributes.strength_ -= 2.0;
}

Herbivore::Herbivore(unsigned x, unsigned y, const Attributes& attributes) :
		Animal(x, y, attributes) {
	locationData.animalType_ = HERBIVORE_CHILD;
	locationData.sightLen_ = actualAttributes.sightLength_;
	locationData.lookingRad = actualAttributes.sightAngle_;
	actualAttributes.maximalSpeed_ -= 1.5;
	actualAttributes.strength_ -= 2.0;
}

void Herbivore::updateStatus() {
	if (locationData.animalType_ == HERBIVORE_CHILD
			&& (time(0) - bornDate) >= Constants::DEFAULT_HERBIVORE_YOUTH_LEN) {
		locationData.animalType_ = HERBIVORE;
		looseState("Childhood");
		currentAction = ActionPtr(new HerbivoreRandomWalking(this));
	}

	currentAction->performAction();
	Action* chosenAction = currentAction->chooseNextAction();
	if (currentAction.get() != chosenAction) {
		currentAction = shared_ptr < Action > (chosenAction);
	}

	eatNeed += Constants::DEFAULT_HERBIVORE_CONSUMPTION
			* Parameters::simulationSpeed;
	sleepNeed += Constants::DEFAULT_HERBIVORE_EXAUSTING
			* Parameters::simulationSpeed;

	if (sleepNeed >= Constants::DEFAULT_MAXIMAL_VALUE)
		sleepNeed = Constants::DEFAULT_MAXIMAL_VALUE;

	if ((time(0) - lastRandomize)
			>= Constants::DEFAULT_INTERVAL / Parameters::simulationSpeed
			&& (rand() % 100) <= floor(actualAttributes.sickChance_)) {
		if (!hasState("Illness"))
			addState(StatePtr(new Illness(this)));
		else {
			looseState("Illness");
		}
		lastRandomize = time(0);
	}
}
