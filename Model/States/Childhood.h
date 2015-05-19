/*
 * Childhood.h
 *
 *  Created on: 17-05-2015
 *      Author: radek
 */

#ifndef CHILDHOOD_H_
#define CHILDHOOD_H_

#include "State.h"

class Childhood: public State {
public:
	Childhood();
	virtual ~Childhood();
	string toString();
	bool isThatMe(string stateName) {
		if (stateName == "Childhood")
			return true;
		return false;
	}
};

#endif /* CHILDHOOD_H_ */
