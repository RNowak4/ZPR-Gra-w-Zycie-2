/*
 * CarnivoreAction.h
 *
 *  Created on: 17-05-2015
 *      Author: radek
 */

#ifndef CARNIVOREACTION_H_
#define CARNIVOREACTION_H_

#include "Action.h"

class CarnivoreAction: public Action {
public:
	CarnivoreAction(Animal* animalPtr_);
	virtual ~CarnivoreAction();
	virtual void performAction() = 0;
	virtual Action* chooseNextAction() = 0;
	virtual void deleteAnimal(const Animal*)=0;
	virtual string toString() = 0;
};

#endif /* CARNIVOREACTION_H_ */
