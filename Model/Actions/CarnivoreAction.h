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
};

#endif /* CARNIVOREACTION_H_ */
