/*
 * AnimalViewParameters.cpp
 *
 *  Created on: 16-05-2015
 *      Author: radek
 */

#include "AnimalViewParameters.h"

AnimalViewParameters::AnimalViewParameters(unsigned width_, unsigned height_,
		unsigned positionX_, unsigned positionY_, AnimalType animalType_) :
		height(height_), width(width_), positionX(positionX_), positionY(positionY_), animalType(animalType_) {
	lookingAngle = 0;
	lookingRad = 0;
}

Coordinates AnimalViewParameters::returnCoordinates() const {
	Coordinates coordinatesToReturn;

	coordinatesToReturn.x = positionX;
	coordinatesToReturn.y = positionY;

	return coordinatesToReturn;
}

LocationData& AnimalViewParameters::returnLocationData() const {
	LocationData dataToReturn;

	dataToReturn.coordinates_.x = positionX;
	dataToReturn.coordinates_.y = positionY;
	dataToReturn.lookingAngle = lookingAngle;
	dataToReturn.lookingRad = lookingRad;

	return dataToReturn;
}
