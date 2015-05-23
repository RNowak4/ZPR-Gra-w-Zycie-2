/* 
 * File:   Attributes.cpp
 * Author: Radek
 * 
 * Created on 12 marca 2015, 00:37
 */

#include "Attributes.h"

// TODO  Generowanie poczatkowych atrybutow na podsatwie modyf.
//		 Beda one potem modyfikowane przez Actions
Attributes::Attributes(const Modifiers& modifiers) {
	speed_ = 5.0;
	sleepNeed_ = 5.0;
	eatNeed_ = 4.0;
	sexNeed_ = 5.0;
	sightLength_ = 5.0;
	sightAngle_ = 5.0;
	naturalDeath_ = 5.0;
}
