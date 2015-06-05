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

/**
@class Attributes
Class that represents animal's attributes.
*/
class Attributes {
private:
	static default_random_engine generator;
	static normal_distribution<double> distribution;
	static normal_distribution<double> distribution2;
	static normal_distribution<double> lifeDistribution;
	static normal_distribution<double> sickChanceDistribution;
	static normal_distribution<double> mutationDistribution;
	static normal_distribution<double> mutationLifeDistribution;
	/**
	 *@function normalizeAll
	 *@brief 	Function is used to normalize attributes numerical values.
	 */
	void normalizeAll();

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

	/**
	 *@function Attributes
	 *@brief 	Default constructor of Attributes class.
	 *@brief		Used to randomly choosing important for animals variables.
	 */
	Attributes();

	/**
	 *@function inheritAttributes
	 *@brief 	Function is used to inherit attributes when child is being borned.
	 *@argument second_attributes -	attributes of the partner.
	 *@return	inherited attributes.
	 */
	Attributes inheritAttributes(const Attributes& second_attributes) const;
};

#endif	/* ATTRIBUTES_H */
