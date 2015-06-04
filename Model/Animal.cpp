/**
 * @file Animal.cpp
 * @brief Implementations of Animal class
 *
 * @author Radoslaw Nowak
 */

#include "Animal.h"

#include <cmath>
#include <cstdlib>

#include "Parameters.h"

Animal::Animal(unsigned x, unsigned y, AnimalType animalType) :
		animalModifiers(), actualAttributes_() {
	locationData_.coordinates_.x = x;
	locationData_.coordinates_.y = y;

	// zeroing important 'move' values
	velocity = 0.0;
	acceleration = 0.0;
	angleVelocity = 0.0;
	locationData_.lookingAngle = 0;
	sex_ = (rand() % 2) ? MALE : FEMALE;
	;
	locationData_.animalSex_ = sex_;

	// setting up time values
	timeSinceCopulation = lastRandomize = bornDate = time(0);
	timeSinceCopulation -= 30;

	// setting up starting important animal values
	eatNeed_ = 2.0;
	sleepNeed_ = 2.0;

	// Animal can have only limited number of children
	childrenNumber = 0;

	dead = false;
}

Animal::Animal(unsigned x, unsigned y, Attributes modifiers,
		AnimalType animalType) :
		Animal(x, y) {
	actualAttributes_ = modifiers;
	dead = false;
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

	dataToReturn->setActionName(currentAction->toString());

	for (auto state : statesList)
		dataToReturn->pushString(state->toString());

	dataToReturn->pushPair(string("Eat need"), floor(eatNeed_ * 10) / 10);
	dataToReturn->pushPair(string("Sleep need"), floor(sleepNeed_ * 10) / 10);
	dataToReturn->pushPair(string("Speed"),
			floor(actualAttributes_.maximalSpeed_ * 10) / 10);
	dataToReturn->pushPair(string("Strength"),
			floor(actualAttributes_.strength_ * 10) / 10);
	dataToReturn->pushPair(string("Children"), childrenNumber);

	return dataToReturn;
}

bool Animal::hasState(const string& stateName) {
	for (auto state : statesList) {
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
	locationData_.coordinates_.x += velocity * Parameters::simulationSpeed
			* cos((double) locationData_.lookingAngle * M_PI / 180.0) / 1.0;
	locationData_.coordinates_.y += velocity * Parameters::simulationSpeed
			* sin((double) locationData_.lookingAngle * M_PI / 180.0) / 1.0;
	locationData_.lookingAngle += angleVelocity * Parameters::simulationSpeed;
	velocity += acceleration * Parameters::simulationSpeed;
	if (velocity >= this->actualAttributes_.maximalSpeed_) {
		velocity = this->actualAttributes_.maximalSpeed_;
		acceleration = 0.0;
	}

	if (locationData_.coordinates_.x <= 0)
		locationData_.lookingAngle = 0;
	else if (locationData_.coordinates_.y <= 0)
		locationData_.lookingAngle = 90;
	else if (locationData_.coordinates_.x >= Parameters::mapWidth)
		locationData_.lookingAngle = 180;
	else if (locationData_.coordinates_.y >= Parameters::mapHeight)
		locationData_.lookingAngle = 270;
}

Animal* Animal::shouldDie() {
	if (dead)
		return this;

	if (eatNeed_ >= 10.0)
		return this;

	if ((time(0) - bornDate) > actualAttributes_.lifeLen_)
		return this;

	return nullptr;
}

void Animal::addState(StatePtr newState) {
	if (!hasState(newState->toString())) {
		statesList.push_back(newState);
	}
}
