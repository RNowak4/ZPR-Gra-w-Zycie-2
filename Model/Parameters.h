/*
 * Parameters.h
 *
 *  Created on: 27 maj 2015
 *      Author: radek
 */

#ifndef MODEL_PARAMETERS_H_
#define MODEL_PARAMETERS_H_

class Parameters {
private:
	Parameters();

public:
	/**
	 *@function setParameters
	 *@brief 	function sets model's parameters
	 *@argument adultWidth_ -	adult animal width
	 *@argument	adultHeigth_ -	adult animal height
	 *@argument youngWidth_ - 	young animal width
	 *@argument youngHeigth_ -	young animal height
	 *@argument mapWidth_ -	map width
	 *@argument mapHeight_ -	map heigth
	 */
	static void setParameters(unsigned adultWidth_, unsigned adultHeigth_,
			unsigned youngWidth_, unsigned youngHeigth_, unsigned mapWidth_,
			unsigned mapHeight_);
	unsigned static adultWidth;
	unsigned static adultHeigth;
	unsigned static youngWidth;
	unsigned static youngHeigth;
	unsigned static mapWidth;
	unsigned static mapHeight;
};

#endif /* MODEL_PARAMETERS_H_ */