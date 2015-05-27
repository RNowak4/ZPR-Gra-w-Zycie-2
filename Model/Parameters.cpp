/*
 * Parameters.cpp
 *
 *  Created on: 27 maj 2015
 *      Author: radek
 */

#include "Parameters.h"

Parameters::Parameters() {
}

void Parameters::setParameters(unsigned adultWidth_, unsigned adultHeigth_,
		unsigned youngWidth_, unsigned youngHeigth_, unsigned mapWidth_,
		unsigned mapHeight_) {
	adultWidth = adultHeigth_;
	adultHeigth = adultHeigth_;
	youngHeigth = youngHeigth_;
	youngWidth = youngWidth_;
	mapHeight = mapHeight_;
	mapWidth = mapWidth_;
}

unsigned Parameters::adultWidth = 50;
unsigned Parameters::adultHeigth = 70;
unsigned Parameters::youngWidth = 30;
unsigned Parameters::youngHeigth = 50;
unsigned Parameters::mapWidth = 20000;
unsigned Parameters::mapHeight = 2000;
