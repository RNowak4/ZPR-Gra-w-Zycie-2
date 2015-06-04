/*
 * Mother.h
 *
 *  Created on: 27 maj 2015
 *      Author: radek
 */

#ifndef MODEL_STATES_MOTHER_H_
#define MODEL_STATES_MOTHER_H_

#include <list>
#include <string>

#include "../Animal.h"
#include "State.h"

class Mother: public State {
private:
	int currentChildNumber;

public:
	Mother(Animal* animalPtr_);
	virtual ~Mother();
	virtual string toString();
	virtual bool isThatMe(string stateName);
	int returnCurrentChildNumber() {
		return currentChildNumber;
	}

	void increaseChildNumber() {
		++currentChildNumber;
	}

	void decreaseChildNumber() {
		--currentChildNumber;
	}
};

#endif /* MODEL_STATES_MOTHER_H_ */
