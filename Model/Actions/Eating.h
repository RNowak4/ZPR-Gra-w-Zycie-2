/*
 * Eating.h
 *
 *  Created on: 24 maj 2015
 *      Author: radek
 */

#ifndef MODEL_STATES_EATING_H_
#define MODEL_STATES_EATING_H_

#include "Action.h"

class Animal;

class Eating: public Action {
private:
	static const unsigned decreaseValue = 150;

public:
	Eating(Animal* animal_ptr);
	~Eating();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
	string toString() {
		return "Eating";
	}
};

#endif /* MODEL_STATES_EATING_H_ */
