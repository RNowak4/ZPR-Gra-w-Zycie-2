/**
 * @file Carnivore.cpp
 * @brief Implementation of the Carnivore class
 *
 * @author Radoslaw Nowak
 */

#include "Carnivore.h"

#include <ctime>

#include "Actions/Action.h"
#include "Constants.h"
#include "Parameters.h"
#include "States/Illness.h"

using namespace std;

Carnivore::Carnivore(unsigned x, unsigned y) :
		Animal(x, y) {
	locationData_.animalType_ = CARNIVORE;
	locationData_.sightLen_ = actualAttributes_.sightLength_;
	locationData_.lookingRad = actualAttributes_.sightAngle_;
}

Carnivore::Carnivore(unsigned x, unsigned y, const Attributes& attributes) :
		Animal(x, y, attributes) {
	locationData_.animalType_ = CARNIVORE_CHILD;
	locationData_.sightLen_ = actualAttributes_.sightLength_;
	locationData_.lookingRad = actualAttributes_.sightAngle_;
}

void Carnivore::updateStatus() {
	static default_random_engine generator;
	uniform_int_distribution<int> distribution(0, 100);

	currentAction->performAction();
	Action* chosenAction = currentAction->chooseNextAction();
	if (currentAction.get() != chosenAction) {
		currentAction = shared_ptr < Action > (chosenAction);
	}

	eatNeed_ += Constants::DEFAULT_CARNIVORE_CONSUMPTION
			* Parameters::simulationSpeed;
	sleepNeed_ += Constants::DEFAULT_CARNIVORE_EXAUSTING
			* Parameters::simulationSpeed;

	if (sleepNeed_ >= Constants::DEFAULT_MAXIMAL_VALUE)
		sleepNeed_ = Constants::DEFAULT_MAXIMAL_VALUE;

	if ((time(0) - lastRandomize) >= Constants::DEFAULT_INTERVAL
			&& distribution(generator) <= actualAttributes_.sickChance_) {
		addState(StatePtr(new Illness(this)));
	}
}
