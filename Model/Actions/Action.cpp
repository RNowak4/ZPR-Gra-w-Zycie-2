/**
* @file Action.cpp
* @brief Implementation of the Action class
*
* @author Radoslaw Nowak
*/


#include "Action.h"

#include "../Model.h"

Model* Action::defaultModelPtr;

Action::Action(Animal* animal_ptr) :
		animalPtr(animal_ptr), modelPtr(defaultModelPtr) {
	modelPtr->addAction(this);
}

Action::~Action() {
	modelPtr->deleteAction(this);
}

default_random_engine Action::generator;
