/*
 * ChildAction.cpp
 *
 *  Created on: 4 cze 2015
 *      Author: radek
 */

#include "ChildAction.h"

ChildAction::ChildAction(Animal* animal_ptr, Animal* mother_ptr) :
		Action(animal_ptr), motherPtr(mother_ptr) {
}

ChildAction::~ChildAction() {
}
