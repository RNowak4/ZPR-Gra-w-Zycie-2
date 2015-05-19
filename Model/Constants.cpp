/**
 * @file Constants.h
 * @brief Implementation of the Constants class
 *
 * @author Radoslaw Nowak
 */

#include "Constants.h"

/**
 *@function setParameters
 *@brief sets constant parameters of the Model
 */
void Constants::setParameters(unsigned adultWidth_, unsigned adultHeigth_,
		unsigned youngWidth_, unsigned youngHeigth_, unsigned mapWidth_,
		unsigned mapHeight_) {
	if (adultWidth_ != 0)
		adultWidth = adultWidth_;
	if (adultHeigth_ != 0)
		adultHeigth = adultHeigth_;
	if (youngWidth_ != 0)
		youngWidth = youngWidth_;
	if (youngHeigth_ != 0)
		youngHeigth = youngHeigth_;
	if (mapWidth_ != 0)
		mapWidth = mapWidth_;
	if (mapHeight_ != 0)
		mapHeight = mapHeight_;
}

unsigned Constants::adultWidth = 20;
unsigned Constants::adultHeigth = 30;
unsigned Constants::youngWidth = 10;
unsigned Constants::youngHeigth = 15;
unsigned Constants::mapWidth = 5000;
unsigned Constants::mapHeight = 5000;
