/**
 * @file Constants.h
 * @brief Class which represents a constant values of the Model parameters
 *
 * @author Radoslaw Nowak
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

class Constants {
private:
	Constants() {
	}

public:
	static void setParameters(unsigned, unsigned, unsigned, unsigned, unsigned,
			unsigned);
	unsigned static adultWidth;
	unsigned static adultHeigth;
	unsigned static youngWidth;
	unsigned static youngHeigth;
	unsigned static mapWidth;
	unsigned static mapHeight;
};

#endif /* CONSTANTS_H_ */
