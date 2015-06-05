/*
 * CarnivoreSleeping.h
 *
 *  Created on: 27 maj 2015
 *      Author: radek
 */

#ifndef MODEL_ACTIONS_CARNIVORESLEEPING_H_
#define MODEL_ACTIONS_CARNIVORESLEEPING_H_

#include "CarnivoreAction.h"

class CarnivoreSleeping: public CarnivoreAction {
private:
	static const unsigned decreaseValue = 200;

public:
	CarnivoreSleeping(Animal* animal_ptr);
	virtual ~CarnivoreSleeping();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
	string toString() {
		return "Sleeping";
	}
};

#endif /* MODEL_ACTIONS_CARNIVORESLEEPING_H_ */
