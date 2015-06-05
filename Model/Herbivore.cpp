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
	locationData_.animalType_ = HERBIVORE;
	locationData_.sightLen_ = actualAttributes_.sightLength_;
	locationData_.lookingRad = actualAttributes_.sightAngle_;
	actualAttributes_.maximalSpeed_ -= 1.5;
	actualAttributes_.strength_ -= 2.0;
}

Herbivore::Herbivore(unsigned x, unsigned y, const Attributes& attributes) :
		Animal(x, y, attributes) {
	locationData_.animalType_ = HERBIVORE_CHILD;
	//addState(StatePtr(new Childhood(this)));
	locationData_.sightLen_ = actualAttributes_.sightLength_;
	locationData_.lookingRad = actualAttributes_.sightAngle_;
	actualAttributes_.maximalSpeed_ -= 1.5;
	actualAttributes_.strength_ -= 2.0;
}

void Herbivore::updateStatus() {
	if (locationData_.animalType_ == HERBIVORE_CHILD
			&& (time(0) - bornDate) >= Constants::DEFAULT_HERBIVORE_YOUTH_LEN) {
		locationData_.animalType_ = HERBIVORE;
		looseState("Childhood");
		currentAction = ActionPtr(new HerbivoreRandomWalking(this));
	}

	currentAction->performAction();
	Action* chosenAction = currentAction->chooseNextAction();
	if (currentAction.get() != chosenAction) {
		currentAction = shared_ptr < Action > (chosenAction);
	}

	/*eatNeed_ += actualAttributes_.eatNeed_ * Parameters::simulationSpeed;
	 sleepNeed_ += actualAttributes_.sleepNeed_ * Parameters::simulationSpeed;*/

	eatNeed_ += Constants::DEFAULT_HERBIVORE_CONSUMPTION
			* Parameters::simulationSpeed;
	sleepNeed_ += Constants::DEFAULT_HERBIVORE_EXAUSTING
			* Parameters::simulationSpeed;

	if (sleepNeed_ >= Constants::DEFAULT_MAXIMAL_VALUE)
		sleepNeed_ = Constants::DEFAULT_MAXIMAL_VALUE;

	if ((time(0) - lastRandomize)
			>= Constants::DEFAULT_INTERVAL / Parameters::simulationSpeed
			&& (rand() % 100) <= floor(actualAttributes_.sickChance_)) {
		if (!hasState("Illness"))
			addState(StatePtr(new Illness(this)));
		else {
			looseState("Illness");
		}
		lastRandomize = time(0);
	}
}
