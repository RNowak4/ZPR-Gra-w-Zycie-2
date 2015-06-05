/*
 * Sleeping.h
 *
 *  Created on: 24 maj 2015
 *      Author: radek
 */

#ifndef MODEL_ACTIONS_SLEEPING_H_
#define MODEL_ACTIONS_SLEEPING_H_

#include "Action.h"

class Sleeping: public Action {
private:
	static const unsigned decreaseValue = 200;

public:
	Sleeping(Animal* animal_ptr);
	virtual ~Sleeping();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
	string toString() {
		return "Sleeping";
	}
};

#endif /* MODEL_ACTIONS_SLEEPING_H_ */
