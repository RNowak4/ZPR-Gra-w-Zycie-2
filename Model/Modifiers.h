/*
 * Modifiers.h
 *
 *  Created on: 16-05-2015
 *      Author: radek
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
	void generateModifiers();
	Modifiers() {
		generateModifiers();
	}
};

#endif /* MODIFIERS_H_ */
