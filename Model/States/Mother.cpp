/*
 * Mother.cpp
 *
 *  Created on: 27 maj 2015
 *      Author: radek
 */

#include "Mother.h"

#include <list>
#include <string>

#include "../Animal.h"

using namespace std;

Mother::Mother(Animal* animalPtr_) :
		State(animalPtr_) {
}

Mother::~Mother() {
}

string Mother::toString() {
	return string("");
}

bool Mother::isThatMe(string stateName) {
	return false;
}
