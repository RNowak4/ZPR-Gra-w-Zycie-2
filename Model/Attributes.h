/**
 * @file Attributes.h
 * @brief Class that represents Animal attributes.
 *
 * @author Radoslaw Nowak
 */

#ifndef ATTRIBUTES_H
#define	ATTRIBUTES_H

struct Modifiers;

class Attributes {
public:
	double maximalSpeed_;
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
		maximalSpeed_  = 2.0;
		sleepNeed_ = 5.0;
		eatNeed_ = 5.0;
		sexNeed_ = 5.0;
		sightLength_ = 5.0;
		sightAngle_ = 5.0;
		naturalDeath_ = 5.0;
	}
};

#endif	/* ATTRIBUTES_H */
