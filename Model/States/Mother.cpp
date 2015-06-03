/*
 * Mother.cpp
 *
 *  Created on: 27 maj 2015
 *      Author: radek
 */

#include "Mother.h"

#include "../Attributes.h"

using namespace std;

Mother::Mother(Animal* animalPtr_) :
		State(animalPtr_) {
	animalPtr->getAttributes().strength_ += 1.5;
}

Mother::~Mother() {
	animalPtr->getAttributes().strength_ -= 1.5;
}

string Mother::toString() {
	return string("Mother");
}

bool Mother::isThatMe(string stateName) {
	if (stateName == "Mother")
		return true;
	return false;
}
