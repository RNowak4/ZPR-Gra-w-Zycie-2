/* 
 * File:   Animal.cpp
 * Author: Radek
 * 
 * Created on 9 marca 2015, 21:29
 */

#include "Animal.h"

Animal::Animal(unsigned x, unsigned y, AnimalType animalType) :
		animalModifiers(), actualAttributes_(animalModifiers), animalViewParameters(
				0, 0, x, y, animalType) {
}

Animal::Animal(unsigned x, unsigned y) :
		animalModifiers(), actualAttributes_(animalModifiers) {
	locationData_.coordinates_.x = x;
	locationData_.coordinates_.y = y;
}

bool Animal::isThatMe(int x, int y) {
	return true;
}

AnimalData* Animal::getAnimalData() {
	AnimalData* dataToReturn = new AnimalData();

	for (auto state : statesVector)
		dataToReturn->pushString(state->toString());

	dataToReturn->pushPair(string("Speed"), actualAttributes_.speed_);
	dataToReturn->pushPair(string("Sex need"), actualAttributes_.sexNeed_);
	//TODO reszta

	return dataToReturn;
}
