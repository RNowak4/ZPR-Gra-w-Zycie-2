/*
 * Fleeing.h
 *
 *  Created on: 24 maj 2015
 *      Author: radek
 */

#ifndef MODEL_ACTIONS_FLEEING_H_
#define MODEL_ACTIONS_FLEEING_H_

#include "Action.h"

class Fleeing: public Action {
private:
	Animal* hunter;

public:
	Fleeing(Animal* animalPtr_, Animal* hunter_);
	virtual ~Fleeing();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
	string toString() {
		return "Fleeing";
	}
};

#endif /* MODEL_ACTIONS_FLEEING_H_ */
