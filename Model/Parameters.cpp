/*
 * Parameters.cpp
 *
 *  Created on: 27 maj 2015
 *      Author: radek
 */

#include "Parameters.h"

Parameters::Parameters() {
}

void Parameters::setParameters(unsigned simulationSpeed_, unsigned adultWidth_, unsigned adultHeigth_,
		unsigned youngWidth_, unsigned youngHeigth_, unsigned mapWidth_,
		unsigned mapHeight_) {
	simulationSpeed = simulationSpeed_;
	adultWidth = adultHeigth_;
	adultHeigth = adultHeigth_;
	youngHeigth = youngHeigth_;
	youngWidth = youngWidth_;
	mapHeight = mapHeight_;
	mapWidth = mapWidth_;
}

double Parameters::simulationSpeed = -1.0;
int Parameters::adultWidth = 50;
int Parameters::adultHeigth = 70;
int Parameters::youngWidth = 30;
int Parameters::youngHeigth = 50;
int Parameters::mapWidth = 20000;
int Parameters::mapHeight = 20000;
