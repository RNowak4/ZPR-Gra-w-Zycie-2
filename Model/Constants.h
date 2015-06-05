/**
 * @file Constants.h
 * @brief Class which represents a constant values of the Model 
 *
 * @author Radoslaw Nowak
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <ctime>

/**
@class Constants
Class that represents Herbivore in the model.
*/
class Constants {
private:
	Constants() {
	}

public:
	/* TODO DELETE */
	unsigned static adultWidth;
	unsigned static adultHeigth;
	unsigned static youngWidth;
	unsigned static youngHeigth;
	unsigned static mapWidth;
	unsigned static mapHeight;
	/* ********** */

	const static double DEFAULT_MAXIMAL_VALUE;

	const static time_t DEFAULT_INTERVAL;

	const static unsigned DEFAULT_COPULATION_RANGE;

	const static double MAX_SIMULATION_SPEED;

	const static unsigned DEFAULT_ACTION_TIME_CHANGE;

	const static unsigned DEFAULT_HERBIVORE_SIGHT_LEN;
	const static unsigned DEFAULT_HERBIVORE_SIGHT_RAD;
	const static unsigned DEFAULT_HERBIVORE_LIFE_LEN;
	const static unsigned DEFAULT_HERBIVORE_HEARING_DISTANCE;
	const static unsigned DEFAULT_HERBIVORE_YOUTH_LEN;
	const static double DEFAULT_HERBIVORE_MAX_SPEED;
	const static double DEFAULT_HERBIVORE_ACCELERATION;
	const static double DEFAULT_HERBIVORE_CONSUMPTION;
	const static double DEFAULT_HERBIVORE_EXAUSTING;
	const static double DEFAULT_HERBIVORE_EATING_SIGHT_REDUCTION;
	const static double DEFAULT_HERBIVORE_SLEEPING_SIGHT_REDUCTION;

	const static unsigned DEFAULT_CARNIVORE_SIGHT_LEN;
	const static unsigned DEFAULT_CARNIVORE_HUNGER;
	const static unsigned DEFAULT_CARNIVORE_SIGHT_RAD;
	const static unsigned DEFAULT_CARNIVORE_LIFE_LEN;
	const static unsigned DEFAULT_CARNIVORE_HEARING_DISTANCE;
	const static unsigned DEFAULT_CARNIVORE_YOUTH_LEN;
	const static double DEFAULT_CARNIVORE_MAX_SPEED;
	const static double DEFAULT_CARNIVORE_ACCELERATION;
	const static double DEFAULT_CARNIVORE_CONSUMPTION;
	const static double DEFAULT_CARNIVORE_EXAUSTING;
};

#endif /* CONSTANTS_H_ */
