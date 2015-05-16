/*
 * AnimalViewParameters.h
 *
 *  Created on: 16-05-2015
 *      Author: radek
 */

#ifndef ANIMALVIEWPARAMETERS_H_
#define ANIMALVIEWPARAMETERS_H_

#include "ViewStructs.h"

using namespace std;

class AnimalViewParameters {
private:
	unsigned lookingRad;
	unsigned lookingAngle;
	unsigned width;
	unsigned height;
	unsigned positionX;
	unsigned positionY;
	AnimalType animalType;

public:
	AnimalViewParameters() { }
	AnimalViewParameters(unsigned, unsigned, unsigned, unsigned, AnimalType);
	LocationData& returnLocationData() const;
	Coordinates returnCoordinates() const;
};

#endif /* ANIMALVIEWPARAMETERS_H_ */
