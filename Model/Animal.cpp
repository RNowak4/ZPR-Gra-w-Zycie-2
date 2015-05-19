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
	locationData_.coordinates_.x = x;
	locationData_.coordinates_.y = y;
	locationData_.lookingAngle = 45;
}

Animal::Animal(unsigned x, unsigned y, const Modifiers& modifiers,
		AnimalType animalType) :
		Animal(x, y) {
}

bool Animal::isThatMe(unsigned x, unsigned y) {
	static const double PI = 3.1415;
	double tmpX, tmpY;
	//tmpX = x * sin((double) locationData_.lookingAngle / (double) 180 * PI);
	//tmpY = y * sin((double) locationData_.lookingAngle / (double) 180 * PI);
	tmpX = x;
	tmpY = y;

	unsigned width, height;
	if (hasState("Childhood")) {
		width = Constants::youngWidth;
		height = Constants::youngHeigth;
	} else {
		width = Constants::adultWidth;
		height = Constants::adultHeigth;
	}

	if (tmpX >= (locationData_.coordinates_.x - width / 2)
			&& tmpX <= (locationData_.coordinates_.x + width / 2)
			&& tmpY >= (locationData_.coordinates_.y - height / 2)
			&& tmpY <= (locationData_.coordinates_.y + height / 2))
		return true;

	return false;
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

bool Animal::hasState(const string& stateName) {
	for (auto state : statesVector) {
		if (state->isThatMe(stateName))
			return true;
	}

	return false;
}

void Animal::updateStatus() {
	currentAction->performAction();
	if (nextAction != currentAction) {
		nextAction = currentAction;
	}
}

void Animal::setPosition(unsigned x, unsigned y) {
	this->locationData_.coordinates_.x = x;
	this->locationData_.coordinates_.y = y;
}

void Animal::setPosition(Coordinates coodrinates) {
	this->locationData_.coordinates_ = coodrinates;
}
