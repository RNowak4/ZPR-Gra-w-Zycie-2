/*
 * Follow.cpp
 *
 *  Created on: 22 maj 2015
 *      Author: radek
 */

#include "Follow.h"

#include <cmath>

#include "../Animal.h"
#include "../Attributes.h"
#include "../Model.h"
#include "RandomWalking.h"

using namespace std;

Follow::Follow(Animal* animalPtr_, Animal* animalPtr) :
		Action(animalPtr_), animalToFollowPtr(animalPtr) {
	this->animalPtr->setVelocity(2.0);
	this->animalPtr->setAcceleration(0.1);
	this->animalPtr->stopTurning();
	this->animalPtr->setLookingAngle(
			Model::countAngle(this->animalPtr->returnCoodtinates(),
					animalToFollowPtr->returnCoodtinates()));
}

Follow::~Follow() {
	modelPtr->deleteAction(this);
}

void Follow::performAction() {
	if (animalToFollowPtr != nullptr) {
		auto lookingAngle = Follow::countToFollowAngle(animalPtr->returnCoodtinates(),
				animalToFollowPtr->returnCoodtinates());

		animalPtr->setLookingAngle(lookingAngle);

		if (Model::countDistance(animalPtr->returnCoodtinates(),
				animalToFollowPtr->returnCoodtinates()) < 40) {
			modelPtr->killAnimal(animalToFollowPtr);
			animalPtr->getAttributes().eatNeed_ -= 4.0;
		}
	}
}

Action* Follow::chooseNextAction() {
	if (animalToFollowPtr == nullptr) {
		return new RandomWalking(this->animalPtr);
	}

	return this;
}

void Follow::deleteAnimal(const Animal* animalPtr) {
	if (this->animalToFollowPtr == animalPtr) {
		animalToFollowPtr = nullptr;
	}
}

unsigned Follow::countToFollowAngle(Coordinates first, Coordinates second) {
	double LenX = first.x - second.x;
	double LenY = first.y - second.y;
	double przeciwProstokatna = Model::countDistance(first, second);
	unsigned angle;

	if (LenX >= 0 && LenY < 0) {
		angle = asin(abs(LenX) / przeciwProstokatna) * 180.0 / M_PI + 90;
	} else if (LenX < 0 && LenY < 0) {
		angle = acos(abs(LenX) / przeciwProstokatna) * 180.0 / M_PI;
	} else if (LenX < 0 && LenY >= 0) {
		angle = asin(abs(LenX) / przeciwProstokatna) * 180.0 / M_PI + 270;
	} else {
		angle = acos(abs(LenX) / przeciwProstokatna) * 180.0 / M_PI + 180;

	}

	return angle;
}
