/**
 * @file Attributes.h
 * @brief Class that represents Animal attributes.
 *
 * @author Radoslaw Nowak
 */

#ifndef ATTRIBUTES_H
#define	ATTRIBUTES_H

struct Modifiers;

#include <random>

using namespace std;

class Attributes {
private:
	static default_random_engine generator;

public:
	double maximalSpeed_;
	double sleepNeed_;
	double eatNeed_;
	double sickChance_;
	double strength_;
	int sightAngle_;
	int sightLength_;
	int hearingRange_;
	int fertility_;
	int lifeLen_;

	Attributes();

	Attributes inheritAttributes(const Attributes& secondAttributes) const;
};

#endif	/* ATTRIBUTES_H */
