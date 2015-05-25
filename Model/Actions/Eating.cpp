/*
 * Eating.cpp
 *
 *  Created on: 24 maj 2015
 *      Author: radek
 */

#include <memory>

#include "Eating.h"

#include "../Animal.h"
#include "../Model.h"
#include "../ViewStructs.h"
#include "Fleeing.h"

using namespace std;

Eating::Eating(Animal* animalPtr_) :
		Action(animalPtr_) {
	animalPtr->setVelocity(0.0);
	animalPtr->returnLocationData()->sightLen_ -= decreaseValue;
}

Eating::~Eating() {
	animalPtr->returnLocationData()->sightLen_ += decreaseValue;
	modelPtr->deleteAction(this);
}

void Eating::performAction() {
	//TODO zwiekszanie wyspania
}

Action* Eating::chooseNextAction() {
	auto animalsVector = modelPtr->getNearlyAnimals(
			animalPtr->returnLocationData()->coordinates_,
			animalPtr->returnLocationData()->sightLen_);

	for (auto animal : animalsVector) {
		if (animalPtr->isDangerous(animal)) {
			return new Fleeing(animalPtr, animal);
		}
	}

	return this;
}

void Eating::deleteAnimal(const Animal*) {
	// nothing to do about that
}
