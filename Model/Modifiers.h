/**
 * @file Modifiers.h
 * @brief Structure that represents modifiers of an animals.
 *
 * @author Radoslaw Nowak
 */

#ifndef MODIFIERS_H_
#define MODIFIERS_H_

struct Modifiers {
	double strength_;
	double speedAbility_;
	double fertility_;
	double sightLength_;
	double naturalDeath_;
	double sightAngle_;

	/**
	 *@function generateModifiers
	 *@brief generate random modifiers.
	 */
	void generateModifiers();

	/**
	 *@function Modifiers
	 *@brief default constructor of the class.
	 */
	Modifiers() {
		generateModifiers();
	}
};

#endif /* MODIFIERS_H_ */
