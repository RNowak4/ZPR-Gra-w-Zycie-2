/*
 * Illness.h
 *
 *  Created on: 17-05-2015
 *      Author: radek
 */

#ifndef ILLNESS_H_
#define ILLNESS_H_

#include <string>

#include "State.h"

class Illness: public State {
public:
	Illness(Animal* animalPtr_);
	~Illness();
	string toString();
	bool isThatMe(string stateName) {
		if(stateName == "Illness") return true;
		return false;
	}
};

#endif /* ILLNESS_H_ */
