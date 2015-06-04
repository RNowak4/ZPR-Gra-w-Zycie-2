/*
 * ChildFleeing.h
 *
 *  Created on: 4 cze 2015
 *      Author: radek
 */

#ifndef MODEL_ACTIONS_CHILDFLEEING_H_
#define MODEL_ACTIONS_CHILDFLEEING_H_

#include "ChildAction.h"

class ChildFleeing: public ChildAction {
private:
	Animal* hunter;

public:
	ChildFleeing(Animal* animalPtr_, Animal* motherPtr_, Animal* hunter);
	virtual ~ChildFleeing();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
	string toString() {
		return "Fleeing";
	}
};

#endif /* MODEL_ACTIONS_CHILDFLEEING_H_ */
