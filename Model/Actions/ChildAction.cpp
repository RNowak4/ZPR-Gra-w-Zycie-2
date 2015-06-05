/**
* @file ChildAction.cpp
* @brief Implementation of the ChildAction class
*
* @author Radoslaw Nowak
*/

#include "ChildAction.h"

ChildAction::ChildAction(Animal* animal_ptr, Animal* mother_ptr) :
		Action(animal_ptr), motherPtr(mother_ptr) {
}

ChildAction::~ChildAction() {
}
