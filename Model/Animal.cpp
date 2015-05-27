/**
 * @file Animal.cpp
 * @brief Implementations of Animal class
 *
 * @author Radoslaw Nowak
 */

#include "Animal.h"

#include <cmath>

#include "Constants.h"
#include "Parameters.h"

Animal::Animal(unsigned x, unsigned y, AnimalType animalType) :
		animalModifiers(), actualAttributes_(animalModifiers), animalViewParameters(
				0, 0, x, y, animalType) {
	locationData_.coordinates_.x = x;
	locationData_.coordinates_.y = y;
	locationData_.lookingAngle = 0;
	sex_ = FEMALE;
	velocity = 0.0;
	acceleration = 0.0;
	angleVelocity = 0.0;
}

Animal::Animal(unsigned x, unsigned y, const Modifiers& modifiers,
		AnimalType animalType) :
		Animal(x, y) {
}

bool Animal::isThatMe(unsigned x, unsigned y) {
	double tmpX, tmpY;
	tmpX = x;
	tmpY = y;

	unsigned width, height;
	if (hasState("Childhood")) {
		width = Parameters::youngWidth;
		height = Parameters::youngHeigth;
	} else {
		width = Parameters::adultWidth;
		height = Parameters::adultHeigth;
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

	dataToReturn->pushPair(string("Speed"), actualAttributes_.maximalSpeed_);
	dataToReturn->pushPair(string("eat need"),
			floor(actualAttributes_.eatNeed_ * 10) / 10);
	dataToReturn->pushPair(string("sleep need"),
			floor(actualAttributes_.sleepNeed_ * 10) / 10);
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

void Animal::setPosition(unsigned x, unsigned y) {
	this->locationData_.coordinates_.x = x;
	this->locationData_.coordinates_.y = y;
}

void Animal::setPosition(Coordinates coodrinates) {
	this->locationData_.coordinates_ = coodrinates;
}

void Animal::doMove() {
	locationData_.coordinates_.x += velocity
			* cos((double) locationData_.lookingAngle * M_PI / 180.0) / 1.0;
	locationData_.coordinates_.y += velocity
			* sin((double) locationData_.lookingAngle * M_PI / 180.0) / 1.0;
	locationData_.lookingAngle += angleVelocity / 1.0;
	locationData_.lookingAngle %= 360;
	velocity += acceleration;
	if (velocity >= this->actualAttributes_.maximalSpeed_) {
		velocity = this->actualAttributes_.maximalSpeed_;
		acceleration = 0.0;
	}

	if (locationData_.coordinates_.x <= 0 || locationData_.coordinates_.y <= 0
			|| locationData_.coordinates_.x >= Parameters::mapWidth
			|| locationData_.coordinates_.x >= Parameters::mapHeight) {
		locationData_.lookingAngle += 180.0;
	}
}

Animal* Animal::shouldDie() {
	if (actualAttributes_.eatNeed_ >= 10.0)
		return this;

	return nullptr;
}
