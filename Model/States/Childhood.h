/*
 * Childhood.h
 *
 *  Created on: 17-05-2015
 *      Author: radek
 */

#ifndef CHILDHOOD_H_
#define CHILDHOOD_H_

#include <string>

#include "State.h"

class Childhood: public State {
public:
	Childhood(Animal* animalPtr_);
	virtual ~Childhood();
	string toString();
	bool isThatMe(string stateName);
};

#endif /* CHILDHOOD_H_ */
