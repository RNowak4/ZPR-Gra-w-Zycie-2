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

Animal::Animal(unsigned x, unsigned y, AnimalType animal_type) :
		actualAttributes() {
	locationData.coordinates_.x = x;
	locationData.coordinates_.y = y;

	// zeroing important 'move' values
	velocity = 0.0;
	acceleration = 0.0;
	angleVelocity = 0.0;
	locationData.lookingAngle = 0;
	sex = (rand() % 2) ? MALE : FEMALE;

	locationData.animalSex_ = sex;
	locationData.lookingRad = actualAttributes.sightAngle_;
	locationData.sightLen_ = actualAttributes.sightLength_;

	// setting up time values
	timeSinceCopulation = lastRandomize = bornDate = time(0);
	timeSinceCopulation -= 30;

	// setting up starting important animal values
	eatNeed = 2.0;
	sleepNeed = 2.0;

	// Animal can have only limited number of children
	childrenNumber = 0;

	dead = false;
}

Animal::Animal(unsigned x, unsigned y, Attributes modifiers,
		AnimalType animal_type) :
		Animal(x, y) {
	actualAttributes = modifiers;
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

	if (tmpX >= (locationData.coordinates_.x - width / 2)
			&& tmpX <= (locationData.coordinates_.x + width / 2)
			&& tmpY >= (locationData.coordinates_.y - height / 2)
			&& tmpY <= (locationData.coordinates_.y + height / 2))
		return true;

	return false;
}

AnimalData* Animal::getAnimalData() {
	AnimalData* data_to_return = new AnimalData();

	data_to_return->setActionName(currentAction->toString());

	for (auto state : statesList)
		data_to_return->pushString(state->toString());

	data_to_return->pushPair(string("Eat need"), floor(eatNeed * 10) / 10);
	data_to_return->pushPair(string("Sleep need"), floor(sleepNeed * 10) / 10);
	data_to_return->pushPair(string("Maximal speed"),
			floor(actualAttributes.maximalSpeed_ * 10) / 10);
	data_to_return->pushPair(string("Strength"),
			(floor(actualAttributes.strength_ * 10) / 10 > 0) ?
					floor(actualAttributes.strength_ * 10) / 10 : 0);
	data_to_return->pushPair(string("Children"), childrenNumber);

	return data_to_return;
}

bool Animal::hasState(const string& stateName) {
	for (auto state : statesList) {
		if (state->isThatMe(stateName))
			return true;
	}

	return false;
}

void Animal::setPosition(unsigned x, unsigned y) {
	this->locationData.coordinates_.x = x;
	this->locationData.coordinates_.y = y;
}

void Animal::setPosition(Coordinates coodrinates) {
	this->locationData.coordinates_ = coodrinates;
}

void Animal::doMove() {
	locationData.coordinates_.x += velocity * Parameters::simulationSpeed
			* cos((double) locationData.lookingAngle * M_PI / 180.0) / 1.0;
	locationData.coordinates_.y += velocity * Parameters::simulationSpeed
			* sin((double) locationData.lookingAngle * M_PI / 180.0) / 1.0;
	locationData.lookingAngle += angleVelocity * Parameters::simulationSpeed;
	velocity += acceleration * Parameters::simulationSpeed;
	if (velocity >= this->actualAttributes.maximalSpeed_) {
		velocity = this->actualAttributes.maximalSpeed_;
		acceleration = 0.0;
	}

	if (locationData.coordinates_.x <= 0)
		locationData.lookingAngle = 0;
	else if (locationData.coordinates_.y <= 0)
		locationData.lookingAngle = 90;
	else if (locationData.coordinates_.x >= Parameters::mapWidth)
		locationData.lookingAngle = 180;
	else if (locationData.coordinates_.y >= Parameters::mapHeight)
		locationData.lookingAngle = 270;
}

Animal* Animal::shouldDie() {
	if (dead)
		return this;

	if (eatNeed >= 10.0)
		return this;

	if ((time(0) - bornDate) > actualAttributes.lifeLen_)
		return this;

	return nullptr;
}

void Animal::addState(StatePtr new_state) {
	if (!hasState(new_state->toString())) {
		statesList.push_back(new_state);
	}
}

void Animal::looseState(const string& state_name) {
	for (auto it = statesList.begin(); it != statesList.end(); ++it) {
		if ((*it)->isThatMe(state_name)) {
			statesList.erase(it);
			return;
		}
	}
}

void Animal::deleteChild(Animal* child_ptr) {
	for (auto it = childrenList.begin(); it != childrenList.end(); ++it) {
		if (*it == child_ptr) {
			childrenList.erase(it);
			break;
		}
	}

	if (childrenList.size() == 0) {
		looseState("Mother");
	}
}
