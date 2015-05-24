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

//TODO TO MA BYC AKCJA  A NIE STATE

class Eating: public Action {
private:
	static const unsigned decreaseValue = 150;

public:
	Eating(Animal* animalPtr);
	~Eating();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
};

#endif /* MODEL_STATES_EATING_H_ */
