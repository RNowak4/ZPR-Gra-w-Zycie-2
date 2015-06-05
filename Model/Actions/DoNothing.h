/*
 * DoNothing.h
 *
 *  Created on: 4 cze 2015
 *      Author: radek
 */

#ifndef MODEL_ACTIONS_DONOTHING_H_
#define MODEL_ACTIONS_DONOTHING_H_

#include "Action.h"

class DoNothing: public Action {
public:
	DoNothing(Animal* animal_ptr);
	virtual ~DoNothing();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
	string toString() {
		return "Doing nothing";
	}
};

#endif /* MODEL_ACTIONS_DONOTHING_H_ */
