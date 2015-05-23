/*
 * Action.cpp
 *
 *  Created on: 17-05-2015
 *      Author: radek
 */

#include "Action.h"

#include "../Model.h"

Model* Action::defaultModelPtr;

Action::Action(Animal* animalPtr_) :
		animalPtr(animalPtr_), modelPtr(defaultModelPtr) {
	modelPtr->addAction(this);
}

Action::~Action() {
	modelPtr->deleteAction(this);
}
