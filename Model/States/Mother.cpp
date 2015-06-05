/**
* @file Mother.cpp
* @brief Implementation of the Mother class
*
* @author Radoslaw Nowak
*/


#include "Mother.h"

#include "../Attributes.h"

using namespace std;

Mother::Mother(Animal* animal_ptr) :
		State(animal_ptr) {
	animalPtr->getAttributes().strength_ += 1.5;
}

Mother::~Mother() {
	animalPtr->getAttributes().strength_ -= 1.5;
}

string Mother::toString() {
	return string("Mother");
}

bool Mother::isThatMe(string state_name) {
	if (state_name == "Mother")
		return true;
	return false;
}
