/**
* @file DoNothing.cpp
* @brief Implementation of the DoNothing class
*
* @author Radoslaw Nowak
*/


#include "DoNothing.h"

#include "../Animal.h"
#include "../Model.h"

DoNothing::DoNothing(Animal* animal_ptr, Animal* mother_ptr) :
		Action(animal_ptr) {
	animalPtr->setVelocity(0.0);
	animalPtr->setAcceleration(0.0);
	animalPtr->stopTurning();
	auto state_ptr = animalPtr->getState("Childhood");
	if(state_ptr != nullptr)
		state_ptr->deleteAnimal(mother_ptr);
}

DoNothing::~DoNothing() {
	modelPtr->deleteAction(this);
}

void DoNothing::performAction() {
	//do nothing
}

Action* DoNothing::chooseNextAction() {
	return this;
}

void DoNothing::deleteAnimal(const Animal*) {
	//do nothing
}
