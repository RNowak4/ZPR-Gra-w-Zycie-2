/* 
 * File:   Attributes.h
 * Author: Radek
 *
 * Created on 12 marca 2015, 00:37
 */

#ifndef ATTRIBUTES_H
#define	ATTRIBUTES_H

#include "Modifiers.h"

class Attributes {
public:
	double speed_;
	double sleepNeed_;
	double eatNeed_;
	double sexNeed_;
	double sightLength_;
	double sightAngle_;
	double naturalDeath_;

public:
	Attributes(const Modifiers& modifiers);

	//TODO temporary
	Attributes() {
		speed_ = 5.0;
		sleepNeed_ = 5.0;
		eatNeed_ = 5.0;
		sexNeed_ = 5.0;
		sightLength_ = 5.0;
		sightAngle_ = 5.0;
		naturalDeath_ = 5.0;
	}
};

#endif	/* ATTRIBUTES_H */
