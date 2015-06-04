/*
 * ChildAction.h
 *
 *  Created on: 4 cze 2015
 *      Author: radek
 */

#ifndef MODEL_ACTIONS_CHILDACTION_H_
#define MODEL_ACTIONS_CHILDACTION_H_

#include "Action.h"

class ChildAction: public Action {
protected:
	Animal* motherPtr;

public:
	ChildAction(Animal* animalPtr_, Animal* motherPtr_);
	virtual ~ChildAction();
	virtual void performAction() = 0;
	virtual Action* chooseNextAction() = 0;
	virtual void deleteAnimal(const Animal*) = 0;
	virtual string toString() = 0;
};

#endif /* MODEL_ACTIONS_CHILDACTION_H_ */
