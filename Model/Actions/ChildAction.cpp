/*
 * ChildAction.cpp
 *
 *  Created on: 4 cze 2015
 *      Author: radek
 */

#include "ChildAction.h"

ChildAction::ChildAction(Animal* animalPtr_, Animal* motherPtr_) :
		Action(animalPtr_), motherPtr(motherPtr_) {
}

ChildAction::~ChildAction() {
}
