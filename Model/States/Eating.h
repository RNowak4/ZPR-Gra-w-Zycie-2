/*
 * Eating.h
 *
 *  Created on: 24 maj 2015
 *      Author: radek
 */

#ifndef MODEL_STATES_EATING_H_
#define MODEL_STATES_EATING_H_

#include <string>

#include "State.h"

class Eating: public State {
private:
	static const unsigned decreaseValue = 200;

public:
	Eating(Animal* animalPtr);
	~Eating();
	bool isThatMe(string stateName);
	string toString();
	void deleteAnimal(const Animal*);
};

#endif /* MODEL_STATES_EATING_H_ */
