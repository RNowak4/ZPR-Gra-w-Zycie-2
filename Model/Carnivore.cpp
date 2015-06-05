/**
 * @file Carnivore.cpp
 * @brief Implementation of the Carnivore class
 *
 * @author Radoslaw Nowak
 */

#include "Carnivore.h"

#include <cmath>
#include <cstdlib>
#include <ctime>

#include "Actions/CarnivoreRandomWalking.h"
#include "Constants.h"
#include "Parameters.h"
#include "States/Childhood.h"
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
	//addState(StatePtr(new Childhood(this)));
	locationData_.sightLen_ = actualAttributes_.sightLength_;
	locationData_.lookingRad = actualAttributes_.sightAngle_;
}

void Carnivore::updateStatus() {
	if (locationData_.animalType_ == CARNIVORE_CHILD
			&& (time(0) - bornDate) >= Constants::DEFAULT_CARNIVORE_YOUTH_LEN) {
		locationData_.animalType_ = CARNIVORE;
		looseState("Childhood");
		currentAction = ActionPtr(new CarnivoreRandomWalking(this));
	}

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

	if ((time(0) - lastRandomize) >= Constants::DEFAULT_INTERVAL/Parameters::simulationSpeed
			&& (rand() % 100) <= floor(actualAttributes_.sickChance_)) {
		if (!hasState("Illness"))
			addState(StatePtr(new Illness(this)));
		else {
			looseState("Illness");
		}
		lastRandomize = time(0);
	}
}
